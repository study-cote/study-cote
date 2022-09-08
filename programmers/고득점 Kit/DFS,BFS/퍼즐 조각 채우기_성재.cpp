#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct Element {
	int row, col;

	Element();
	Element(int, int);
};

struct List {
	Element* dir[4];

	List();
	~List();
};

struct Puzzle {
	int size;
	Element start[4];

	Puzzle(int, int);
};

struct Block {
	int depth, dir, before;
};

struct BlockElement {
	int row, col, depth;
};

Puzzle getList(vector<vector<int>>&, List***&, int, int);
list<Block> getEmptyBlock(vector<vector<int>>&, int, int);
bool isSame(List***&, list<Block>&, Puzzle&, int**);

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;

	List*** pos = new List * *[table.size()];
	int** visit = new int* [table.size()];
	for (int i = 0; i < table.size(); i++) {
		pos[i] = new List * [table.size()];
		visit[i] = new int[table.size()];
		for (int j = 0; j < table.size(); j++) {
			pos[i][j] = NULL;
			visit[i][j] = 0;
		}
	}

	vector<Puzzle> puzzle;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table.size(); j++) {
			if (table[i][j] == 1) {
				puzzle.push_back(getList(table, pos, i, j));
			}
		}
	}
	for (int i = 0; i < game_board.size(); i++) {
		for (int j = 0; j < game_board.size(); j++) {
			if (game_board[i][j] == 0) {
				list<Block> blockQ = getEmptyBlock(game_board, i, j);
				for (int k = 0; k < puzzle.size(); k++) {
					if (blockQ.size() + 1 == puzzle[k].size) {
						if (isSame(pos, blockQ, puzzle[k], visit)) {
							answer += puzzle[k].size;
							puzzle.erase(puzzle.begin() + k);
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table.size(); j++) {
			if (pos[i][j]) {
				delete pos[i][j];
			}
		}
		delete[] pos[i], visit[i];
	}
	delete[] pos, visit;

	return answer;
}

Element::Element() {

}

Element::Element(int r, int c) : row(r), col(c) {

}

List::List() {
	for (int i = 0; i < 4; i++) {
		dir[i] = NULL;
	}
}

List::~List() {
	for (int i = 0; i < 4; i++) {
		if (dir[i]) {
			delete dir[i];
		}
	}
}

Puzzle::Puzzle(int r, int c) : size(1) {
	for (int i = 0; i < 4; i++) {
		start[i] = { r,c };
	}
}

Puzzle getList(vector<vector<int>>& table, List***& pos, int r, int c) {
	queue<Element> Q;
	Element temp = { r,c };
	Q.push(temp);
	pos[r][c] = new List();

	Puzzle newPuzzle(r, c);

	int size = table.size(), num = 0;
	while (!Q.empty()) {
		Element cur = Q.front();
		Q.pop();
		if (table[cur.row][cur.col]) {
			table[cur.row][cur.col] = 0;
			num++;
			if (cur.col > newPuzzle.start[1].col || (cur.col == newPuzzle.start[1].col && cur.row < newPuzzle.start[1].row)) {
				newPuzzle.start[1] = { cur.row,cur.col };
			}
			if (cur.row > newPuzzle.start[2].row || (cur.row == newPuzzle.start[2].row && cur.col > newPuzzle.start[2].col)) {
				newPuzzle.start[2] = { cur.row,cur.col };
			}
			if (cur.col < newPuzzle.start[3].col || (cur.col == newPuzzle.start[3].col && cur.row > newPuzzle.start[3].row)) {
				newPuzzle.start[3] = { cur.row,cur.col };
			}
			if (cur.col + 1 < size && table[cur.row][cur.col + 1]) {
				if (!pos[cur.row][cur.col + 1]) {
					pos[cur.row][cur.col + 1] = new List();
				}
				pos[cur.row][cur.col]->dir[0] = new Element(cur.row, cur.col + 1);
				pos[cur.row][cur.col + 1]->dir[2] = new Element(cur.row, cur.col);
				temp = { cur.row,cur.col + 1 };
				Q.push(temp);
			}
			if (cur.row + 1 < size && table[cur.row + 1][cur.col]) {
				if (!pos[cur.row + 1][cur.col]) {
					pos[cur.row + 1][cur.col] = new List();
				}
				pos[cur.row][cur.col]->dir[1] = new Element(cur.row + 1, cur.col);
				pos[cur.row + 1][cur.col]->dir[3] = new Element(cur.row, cur.col);
				temp = { cur.row + 1,cur.col };
				Q.push(temp);
			}
			if (cur.col - 1 >= 0 && table[cur.row][cur.col - 1]) {
				if (!pos[cur.row][cur.col - 1]) {
					pos[cur.row][cur.col - 1] = new List();
				}
				pos[cur.row][cur.col]->dir[2] = new Element(cur.row, cur.col - 1);
				pos[cur.row][cur.col - 1]->dir[0] = new Element(cur.row, cur.col);
				temp = { cur.row, cur.col - 1 };
				Q.push(temp);
			}
			if (cur.row - 1 >= 0 && table[cur.row - 1][cur.col]) {
				if (!pos[cur.row - 1][cur.col]) {
					pos[cur.row - 1][cur.col] = new List();
				}
				pos[cur.row][cur.col]->dir[3] = new Element(cur.row - 1, cur.col);
				pos[cur.row - 1][cur.col]->dir[1] = new Element(cur.row, cur.col);
				temp = { cur.row - 1,cur.col };
				Q.push(temp);
			}
		}
	}

	newPuzzle.size = num;

	return newPuzzle;
}

list<Block> getEmptyBlock(vector<vector<int>>& game_board, int r, int c) {
	list<Block> Q;
	queue<BlockElement> visitQ;
	BlockElement pos = { r,c,1 };
	visitQ.push(pos);
	game_board[r][c] = 1;

	int size = game_board.size();
	Block temp;
	int before = 1;
	while (!visitQ.empty()) {
		BlockElement cur = visitQ.front();
		visitQ.pop();
		if (cur.col + 1 < size && !game_board[cur.row][cur.col + 1]) {
			game_board[cur.row][cur.col + 1] = 1;
			temp = { cur.depth + 1,0,before };
			Q.push_back(temp);
			pos = { cur.row,cur.col + 1,cur.depth + 1 };
			visitQ.push(pos);
		}
		if (cur.row + 1 < size && !game_board[cur.row + 1][cur.col]) {
			game_board[cur.row + 1][cur.col] = 1;
			temp = { cur.depth + 1,1,before };
			Q.push_back(temp);
			pos = { cur.row + 1,cur.col,cur.depth + 1 };
			visitQ.push(pos);
		}
		if (cur.col - 1 >= 0 && !game_board[cur.row][cur.col - 1]) {
			game_board[cur.row][cur.col - 1] = 1;
			temp = { cur.depth + 1,2,before };
			Q.push_back(temp);
			pos = { cur.row,cur.col - 1,cur.depth + 1 };
			visitQ.push(pos);
		}
		if (cur.row - 1 >= 0 && !game_board[cur.row - 1][cur.col]) {
			game_board[cur.row - 1][cur.col] = 1;
			temp = { cur.depth + 1,3,before };
			Q.push_back(temp);
			pos = { cur.row - 1,cur.col,cur.depth + 1 };
			visitQ.push(pos);
		}
		before++;
	}

	return Q;
}

bool isSame(List***& pos, list<Block>& Q, Puzzle& puzzle, int** visit) {
	for (int i = 0; i < 4; i++) {
		queue<Element*> visitQ;
		queue<Element*> blockSeq;
		int row = puzzle.start[i].row, col = puzzle.start[i].col;
		Element* temp = new Element(row, col);
		visitQ.push(temp);
		blockSeq.push(temp);
		visit[row][col] = 1;

		list<Block>::iterator listPtr = Q.begin();
		bool same = true;
		int before = 1;
		while (!blockSeq.empty()) {
			Element* cur = blockSeq.front();
			blockSeq.pop();
			List* curPtr = pos[cur->row][cur->col];
			for (int j = 0; j < 4; j++) {
				temp = curPtr->dir[(i + j) % 4];
				if (temp && !visit[temp->row][temp->col]) {
					visit[temp->row][temp->col] = visit[cur->row][cur->col] + 1;
					visitQ.push(temp);
					blockSeq.push(temp);
					if (visit[temp->row][temp->col] != (*listPtr).depth || j != (*listPtr).dir || before != (*listPtr).before) {
						same = false;
					}
					listPtr++;
				}
			}
			before++;
		}
		while (!visitQ.empty()) {
			temp = visitQ.front();
			visitQ.pop();
			visit[temp->row][temp->col] = 0;
		}
		if (same) {
			return true;
		}
	}

	return false;
}