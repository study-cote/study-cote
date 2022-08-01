#include <iostream>
#include <string>

struct Stack {
	int row, col;
	Stack* next;

	Stack(int, int, Stack*);
};

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		std::string str;
		int** visit = new int* [n];
		for (int i = 0; i < n; i++) {
			std::cin >> str;
			visit[i] = new int[n];
			for (int j = 0; j < n; j++) {
				if (str[j] == '*') {
					visit[i][j] = 2;
				}
				else {
					visit[i][j] = 0;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					int r, c;
					r = i;
					c = j;
					bool isEmpty = true;
					if (i + 1 < n) {
						if (c + 1 < n && visit[r + 1][c + 1] == 2) {
							isEmpty = false;
						}
						if (visit[r + 1][c] == 2) {
							isEmpty = false;
						}
						if (c - 1 >= 0 && visit[r + 1][c - 1] == 2) {
							isEmpty = false;
						}
					}
					if (isEmpty) {
						if (c + 1 < n && visit[r][c + 1] == 2) {
							isEmpty = false;
						}
						if (c - 1 >= 0 && visit[r][c - 1] == 2) {
							isEmpty = false;
						}
					}
					if (r - 1 >= 0 && isEmpty) {
						if (c + 1 < n && visit[r - 1][c + 1] == 2) {
							isEmpty = false;
						}
						if (visit[r - 1][c] == 2) {
							isEmpty = false;
						}
						if (c - 1 >= 0 && visit[r - 1][c - 1] == 2) {
							isEmpty = false;
						}
					}
					Stack* top = NULL, * temp;
					if (isEmpty) {
						top = new Stack(r, c, top);
						while (top) {
							r = top->row;
							c = top->col;
							temp = top;
							top = top->next;
							delete temp;
							visit[r][c] = 1;
							isEmpty = true;
							if (r + 1 < n) {
								if (c + 1 < n && visit[r + 1][c + 1] == 2) {
									isEmpty = false;
								}
								if (visit[r + 1][c] == 2) {
									isEmpty = false;
								}
								if (c - 1 >= 0 && visit[r + 1][c - 1] == 2) {
									isEmpty = false;
								}
							}
							if (isEmpty) {
								if (c + 1 < n && visit[r][c + 1] == 2) {
									isEmpty = false;
								}
								if (c - 1 >= 0 && visit[r][c - 1] == 2) {
									isEmpty = false;
								}
							}
							if (r - 1 >= 0 && isEmpty) {
								if (c + 1 < n && visit[r - 1][c + 1] == 2) {
									isEmpty = false;
								}
								if (visit[r - 1][c] == 2) {
									isEmpty = false;
								}
								if (c - 1 >= 0 && visit[r - 1][c - 1] == 2) {
									isEmpty = false;
								}
							}
							if (isEmpty) {
								if (r + 1 < n) {
									if (c + 1 < n && visit[r + 1][c + 1] == 0) {
										top = new Stack(r + 1, c + 1, top);
									}
									if (visit[r + 1][c] == 0) {
										top = new Stack(r + 1, c, top);
									}
									if (c - 1 >= 0 && visit[r + 1][c - 1] == 0) {
										top = new Stack(r + 1, c - 1, top);
									}
								}
								if (c + 1 < n && visit[r][c + 1] == 0) {
									top = new Stack(r, c + 1, top);
								}
								if (c - 1 >= 0 && visit[r][c - 1] == 0) {
									top = new Stack(r, c - 1, top);
								}
								if (r - 1 >= 0) {
									if (c + 1 < n && visit[r - 1][c + 1] == 0) {
										top = new Stack(r - 1, c + 1, top);
									}
									if (visit[r - 1][c] == 0) {
										top = new Stack(r - 1, c, top);
									}
									if (c - 1 >= 0 && visit[r - 1][c - 1] == 0) {
										top = new Stack(r - 1, c - 1, top);
									}
								}
							}
						}
						count++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					visit[i][j] = true;
					count++;
				}
			}
		}
		std::cout << '#' << testcase << ' ' << count << '\n';
		for (int i = 0; i < n; i++) {
			delete[] visit[i];
		}
		delete[] visit;
	}

	return 0;
}

Stack::Stack(int r, int c, Stack* ptr) :row(r), col(c), next(ptr) {

}