#include <iostream>

int main(void) {
	for (int testcase = 0; testcase < 10; testcase++) {
		int t;
		std::cin >> t;
		
		int arr[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				std::cin >> arr[i][j];
			}
		}
		int col = 0;
		for (; col < 100; col++) {
			if (arr[99][col] == 2) {
				break;
			}
		}
		for (int row = 98; row > 0; row--) {
			if (col - 1 >= 0 && arr[row][col - 1]) {
				for (col--; col - 1 >= 0 && arr[row][col - 1]; col--);
			}
			else if (col + 1 < 100 && arr[row][col + 1]) {
				for (col++; col + 1 < 100 && arr[row][col + 1]; col++);
			}
		}
		std::cout << '#' << t << ' ' << col << '\n';
	}

	return 0;
}