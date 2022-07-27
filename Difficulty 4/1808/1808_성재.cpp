#include <iostream>
#include <cmath>

void search(bool*, int*&, int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		bool* valid = new bool[10];
		for (int i = 0; i < 10; i++) {
			int v;
			std::cin >> v;
			if (v) {
				valid[i] = true;
			}
			else {
				valid[i] = false;
			}
		}
		int n;
		std::cin >> n;
		int* answer = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			int count = 0;
			int j = i;
			for (; j; j /= 10, count++) {
				if (!valid[j % 10]) {
					break;
				}
			}
			if (!j) {
				answer[i] = count;
			}
			else {
				answer[i] = -1;
			}
		}
		search(valid, answer, n);
		
		std::cout << '#' << testcase << ' ';
		if (answer[n] > 0) {
			std::cout << answer[n] + 1 << '\n';
		}
		else {
			std::cout << "-1\n";
		}

		delete[] valid, answer;
	}

	return 0;
}

void search(bool* valid, int*& answer, int cur) {
	for (int i = 1; i <= (int)std::sqrt(cur); i++) {
		if (!(cur % i)) {
			if (cur != i && answer[i] == -1) {
				search(valid, answer, i);
			}
			if (cur != cur / i && answer[cur / i] == -1) {
				search(valid, answer, cur / i);
			}
			if (answer[i] > 0 && answer[cur / i] > 0) {
				int result = answer[i] + answer[cur / i] + 1;
				if (answer[cur] < 0) {
					answer[cur] = result;
				}
				else if (result < answer[cur]) {
					answer[cur] = result;
				}
			}
		}
	}
}