#include <iostream>
#include <queue>

struct Matrix {
	int row, col;

	Matrix(int, int);
	bool operator<(const Matrix& m) const;
};

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		int** arr = new int* [n];
		bool** visit = new bool* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
			visit[i] = new bool[n];
			for (int j = 0; j < n; j++) {
				std::cin >> arr[i][j];
				visit[i][j] = false;
			}
		}
		std::priority_queue<Matrix> PQ;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && arr[i][j]) {
					int r = i;
					for (; r + 1 < n && arr[r + 1][j]; r++);
					int c = j;
					for (; c + 1 < n && arr[i][c + 1]; c++);
					Matrix temp(r - i + 1, c - j + 1);
					PQ.push(temp);
					for (int a = i; a <= r; a++) {
						for (int b = j; b <= c; b++) {
							visit[a][b] = true;
						}
					}
				}
			}
		}
		std::cout << '#' << testcase << ' ' << PQ.size() << ' ';
		while (!PQ.empty()) {
			Matrix temp = PQ.top();
			PQ.pop();
			std::cout << temp.row << ' ' << temp.col << ' ';
		}
		std::cout << '\n';

		for (int i = 0; i < n; i++) {
			delete[] arr[i], visit[i];
		}
		delete[] arr, visit;
	}

	return 0;
}

Matrix::Matrix(int r, int c) : row(r), col(c) {

}

bool Matrix::operator<(const Matrix& m) const {
	if (this->row * this->col == m.row * m.col) {
		return this->row > m.row;
	}
	else {
		return this->row * this->col > m.row * m.col;
	}
}