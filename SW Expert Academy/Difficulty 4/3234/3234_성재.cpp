#include <iostream>
#include <cmath>

int facto[10];
bool* visit;

void calcul(int*, int&, int, int, int, int, int);

int main(void) {
	int t;
	std::cin >> t;
	facto[0] = 1;
	for (int i = 1; i < 9; i++) {
		facto[i] = facto[i - 1] * i;
	}
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		int sum = 0;
		int* arr = new int[n];
		visit = new bool[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
			sum += arr[i];
			visit[i] = false;
		}
		int answer = 0;
		calcul(arr, answer, n, 0, 0, 0, (sum + 1) / 2);

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] arr, visit;
	}

	return 0;
}

void calcul(int* arr, int& answer, int n, int cur, int sumL, int sumR, int goal) {
	if (cur < n) {
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				if (sumL + arr[i] >= goal) {
					answer += (facto[n - cur - 1] * (int)pow(2, n - cur - 1));
				}
				else {
					calcul(arr, answer, n, cur + 1, sumL + arr[i], sumR, goal);
				}
				if (sumR + arr[i] <= sumL) {
					calcul(arr, answer, n, cur + 1, sumL, sumR + arr[i], goal);
				}
				visit[i] = false;
			}
		}
	}
}