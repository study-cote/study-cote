#include <iostream>
#include <random>

void quickSort(int*, int, int);
void swap(int*, int, int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		quickSort(arr, 0, n - 1);
		
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (i % 3 != 2) {
				sum += arr[i];
			}
		}

		std::cout << '#' << testcase << ' ' << sum << '\n';

		delete[] arr;
	}

	return 0;
}

void quickSort(int* arr, int l, int r) {
	if (l < r) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(l, r);

		int pivot = dis(gen);
		swap(arr, l, pivot);

		int i = l, j = r + 1;
		while (i < j) {
			for (i++; i <= r && arr[i] > arr[l]; i++);
			for (j--; j > l && arr[j] < arr[l]; j--);
			if (i < j) {
				swap(arr, i, j);
			}
		}
		swap(arr, l, j);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}