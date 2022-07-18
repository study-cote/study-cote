#include <iostream>

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int t;
		std::cin >> t;
		int arr[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				std::cin >> arr[i][j];
			}
		}
		int answer, min = 10001;
		for (int i = 99; i >= 0; i--) {
			if (arr[0][i]) {
				int col = i, count = 0;
				for (int row = 0; row < 100; row++, count++) {
					if (col + 1 < 100 && arr[row][col + 1]) {
						for (; col + 1 < 100 && arr[row][col + 1]; col++, count++);
					}
					else if (col - 1 >= 0 && arr[row][col - 1]) {
						for (; col - 1 >= 0 && arr[row][col - 1]; col--, count++);
					}
				}
				if (count < min) {
					min = count;
					answer = i;
				}
			}
		}
		std::cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}