#include <iostream>
#include <string>

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::string str;
		std::cin >> n >> str;
		int** arr = new int* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
		}
		if (str == "left") {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					std::cin >> arr[i][j];
				}
			}
		}
		else if (str == "right") {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					std::cin >> arr[i][j];
				}
			}
		}
		else if (str == "up") {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					std::cin >> arr[j][i];
				}
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					std::cin >> arr[j][i];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int cur = 0, search = 0, next;
			for (; search < n; search++) {
				if (arr[i][search]) {
					break;
				}
			}
			while (search < n) {
				for (next = search + 1; next < n; next++) {
					if (arr[i][next]) {
						break;
					}
				}
				int temp;
				if (next < n && arr[i][search] == arr[i][next]) {
					temp = arr[i][search] * 2;
					arr[i][search] = 0;
					arr[i][next] = 0;
					for (search = next + 1; search < n; search++) {
						if (arr[i][search]) {
							break;
						}
					}
				}
				else {
					temp = arr[i][search];
					arr[i][search] = 0;
					search = next;
				}
				arr[i][cur++] = temp;
			}
		}

		std::cout << '#' << testcase << '\n';
		if (str == "left") {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					std::cout << arr[i][j] << ' ';
				}
				std::cout << '\n';
			}
		}
		else if (str == "right") {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					std::cout << arr[i][j] << ' ';
				}
				std::cout << '\n';
			}
		}
		else if (str == "up") {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					std::cout << arr[j][i] << ' ';
				}
				std::cout << '\n';
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					std::cout << arr[j][i] << ' ';
				}
				std::cout << '\n';
			}
		}

		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	return 0;
}