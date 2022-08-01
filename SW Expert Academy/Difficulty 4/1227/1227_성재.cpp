#include <iostream>
#include <string>

struct Stack {
	int row, col;
	Stack* next;

	Stack(int, int, Stack*);
};

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int t;
		std::cin >> t;
		std::string* map = new std::string[100];
		bool** visit = new bool* [100];
		for (int i = 0; i < 100; i++) {
			std::cin >> map[i];
			visit[i] = new bool[100];
			for (int j = 0; j < 100; j++) {
				if (map[i][j] == '1') {
					visit[i][j] = true;
				}
				else {
					visit[i][j] = false;
				}
			}
		}
		Stack* top = NULL;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (map[i][j] == '2') {
					top = new Stack(i, j, top);
					visit[i][j] = true;
					break;
				}
			}
		}
		int row, col;
		Stack* temp;
		bool hasRoad = false;
		while (top) {
			row = top->row;
			col = top->col;
			temp = top;
			top = top->next;
			delete temp;
			if (map[row][col] == '3') {
				hasRoad = true;
				break;
			}
			if (row + 1 < 100 && !visit[row + 1][col]) {
				top = new Stack(row + 1, col, top);
				visit[row + 1][col] = true;
			}
			if (col + 1 < 100 && !visit[row][col + 1]) {
				top = new Stack(row, col + 1, top);
				visit[row][col + 1] = true;
			}
			if (row - 1 >= 0 && !visit[row - 1][col]) {
				top = new Stack(row - 1, col, top);
				visit[row - 1][col] = true;
			}
			if (col - 1 >= 0 && !visit[row][col - 1]) {
				top = new Stack(row, col - 1, top);
				visit[row][col - 1] = true;
			}
		}
		std::cout << '#' << testcase << ' ';
		if (hasRoad) {
			std::cout << "1\n";
		}
		else {
			std::cout << "0\n";
		}
		while (top) {
			temp = top;
			top = top->next;
			delete top;
		}
		for (int i = 0; i < 100; i++) {
			delete[] visit[i];
		}
		delete[] map, visit;
	}

	return 0;
}

Stack::Stack(int r, int c, Stack* ptr) : row(r), col(c), next(ptr) {

}