#include <iostream>

void print(char*, int, int);

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int n;
		std::cin >> n;
		int a, b, c;
		char* arr = new char[n + 1];
		if (n % 2) {
			for (int i = 1; i <= n / 2; i++) {
				std::cin >> a >> arr[i] >> b >> c;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				std::cin >> a >> arr[i];
			}
		}
		else {
			for (int i = 1; i < n / 2; i++) {
				std::cin >> a >> arr[i] >> b >> c;
			}
			std::cin >> a >> arr[n / 2] >> b;
			for (int i = n / 2 + 1; i <= n; i++) {
				std::cin >> a >> arr[i];
			}
		}
		std::cout << '#' << testcase << ' ';
		print(arr, n, 1);
		std::cout << '\n';
		delete[] arr;
	}

	return 0;
}

void print(char* arr, int n, int cur) {
	if (cur <= n) {
		print(arr, n, cur * 2);
		std::cout << arr[cur];
		print(arr, n, cur * 2 + 1);
	}
}