#include <iostream>

double** probability;
bool* visit;
double* mem;

void search(const int, int, int);

int main(void) {
	int t;
	std::cin >> t;
	std::cout << std::fixed;
	std::cout.precision(6);
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		probability = new double* [n];
		int size = 1;
		for (int i = 0; i < n; i++) {
			size *= 2;
		}
		visit = new bool[size];
		mem = new double[size];
		for (int i = 0; i < n; i++) {
			probability[i] = new double[n];
			for (int j = 0; j < n; j++) {
				int num;
				std::cin >> num;
				probability[i][j] = (double)num / 100;
			}
		}
		for (int i = 0; i < size; i++) {
			visit[i] = false;
		}
		visit[0] = true;
		mem[0] = 1;

		search(n, size - 1, 0);
		std::cout << '#' << testcase << ' ' << mem[size - 1] * 100 << '\n';

		for (int i = 0; i < n; i++) {
			delete[] probability[i];
		}
		delete[] probability, visit, mem;
	}

	return 0;
}

void search(const int n, int cur, int person) {
	if (cur) {
		int pos = 1;
		double max = -1;
		for (int i = 0; i < n; i++, pos = pos << 1) {
			if (cur & pos) {
				int temp = cur - pos;
				if (!visit[temp]) {
					search(n, temp, person + 1);
				}
				if (probability[person][i] * mem[temp] > max) {
					max = probability[person][i] * mem[temp];
				}
			}
		}
		visit[cur] = true;
		mem[cur] = max;
	}
}