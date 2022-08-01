#include <iostream>

struct Dir {
	int x, y;
};

struct List {
	int data, dir;
	List* next;

	List(int, int, List*);
};

struct Stack {
	int row, col, dir, mem;
	Stack* next;

	Stack(int, int, int, int, Stack*);
};

int main(void) {
	int t;

	std::cin >> t;
	Dir dirArr[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	for (int testcase = 1; testcase <= t; testcase++) {
		if (testcase == 36) {
			// test
			int temp = 1;
		}
		int r, c;

		std::cin >> r >> c;

		char** arr = new char* [r];
		List*** list = new List **[r];
		for (int i = 0; i < r; i++) {
			arr[i] = new char[c];
			list[i] = new List * [c];
			for (int j = 0; j < c; j++) {
				std::cin >> arr[i][j];
				list[i][j] = NULL;
			}
		}
		Stack* top = NULL;

		int row = 0, col = 0, dir = 0, mem = 0;
		bool isStop = false, endLoop = false;
		while (!endLoop) {
			if (arr[row][col] >= '0' && arr[row][col] <= '9') {
				mem = arr[row][col] - '0';
			}
			else {
				bool temp;
				switch (arr[row][col]) {
				case '<':
					dir = 2;
					break;
				case '>':
					dir = 0;
					break;
				case '^':
					dir = 3;
					break;
				case 'v':
					dir = 1;
					break;
				case '_':
					if (mem == 0) {
						dir = 0;
					}
					else {
						dir = 2;
					}
					break;
				case '|':
					if (mem == 0) {
						dir = 1;
					}
					else {
						dir = 3;
					}
					break;
				case '?':
					temp = false;
					for (List* search = list[row][col]; search; search = search->next) {
						if (search->data == mem) {
							temp = true;
							break;
						}
					}
					if (!temp) {
						dir = 0;
						top = new Stack(row, col, 1, mem, top);
						top = new Stack(row, col, 2, mem, top);
						top = new Stack(row, col, 3, mem, top);
					}
					else {
						if (!top) {
							endLoop = true;
						}
					}
					break;
				case '@':
					isStop = true;
					endLoop = true;
					break;
				case '+':
					mem = (mem + 1) % 16;
					break;
				case '-':
					mem = (mem + 15) % 16;
					break;
				}
			}
			for (List* search = list[row][col]; search; search = search->next) {
				if (search->data == mem && search->dir == dir) {
					if (top) {
						row = top->row;
						col = top->col;
						dir = top->dir;
						mem = top->mem;
						Stack* temp = top;
						top = top->next;
						delete temp;
					}
					else {
						endLoop = true;
					}
					break;
				}
			}
			list[row][col] = new List(mem, dir, list[row][col]);
			row = (row + dirArr[dir].y + r) % r;
			col = (col + dirArr[dir].x + c) % c;
		}
		std::cout << '#' << testcase << ' ';
		if (isStop) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
		for (int i = 0; i < r; i++) {
			delete[] arr[i];
			for (int j = 0; j < c; j++) {
				for (List* ptr = list[i][j]; ptr;) {
					List* temp = ptr;
					ptr = ptr->next;
					delete temp;
				}
			}
		}
		delete[] arr;
		while (top) {
			Stack* temp = top;
			top = top->next;
			delete top;
		}
	}

	return 0;
}

List::List(int m, int d, List* ptr) : data(m), dir(d), next(ptr) {

}

Stack::Stack(int r, int c, int d, int m, Stack* ptr) : row(r), col(c), dir(d), mem(m), next(ptr) {

}