#include <iostream>
#include <set>
#include <random>

void quickSort(int*, int, int);
void swap(int*, int, int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		std::set<int> s;
		s.insert(0);
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		quickSort(arr, 0, n - 1);
		for (int i = 0; i < n;) {
			std::set<int> s2(s);
			int trail = arr[i];
			for (int count = 1; i < n && arr[i] == trail; i++, count++) {
				for (std::set<int>::iterator j = s2.begin(); j != s2.end(); j++) {
					s.insert(*j + arr[i] * count);
				}
			}
		}
		std::cout << '#' << testcase << ' ' << s.size() << '\n';
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
			for (i++; i <= r && arr[i] < arr[l]; i++);
			for (j--; j > l && arr[j] > arr[l]; j--);
			swap(arr, i, j);
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