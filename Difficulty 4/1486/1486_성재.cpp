#include <iostream>

int min;

void search(int*&, const int, const int, const int, const int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n, b;
		std::cin >> n >> b;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		min = 200001;
		search(arr, n, b, 0, 0);
		std::cout << '#' << testcase << ' ' << min - b << '\n';
		
		delete[] arr;
	}

	return 0;
}

void search(int*& arr, const int n, const int b, const int cur, const int sum) {
	if (cur == n) {
		if (sum >= b && sum < min) {
			min = sum;
		}
	}
	else {
		search(arr, n, b, cur + 1, sum);
		search(arr, n, b, cur + 1, sum + arr[cur]);
	}
}