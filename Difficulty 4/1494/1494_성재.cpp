#include <iostream>

struct Pos {
	int x, y;
};

void func(Pos*, bool*, int, int, int, unsigned long long&);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		Pos* arr = new Pos[n];
		bool* visit = new bool[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i].x >> arr[i].y;
			visit[i] = false;
		}
		unsigned long long answer = ~0ull;
		func(arr, visit, 0, n / 2, n, answer);

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] arr, visit;
	}

	return 0;
}

void func(Pos* arr, bool* visit, int cur, int remain, int n, unsigned long long& answer) {
	if (!remain) {
		int xsum = 0, ysum = 0;
		for (int i = 0; i < n; i++) {
			if (visit[i]) {
				xsum += arr[i].x;
				ysum += arr[i].y;
			}
			else {
				xsum -= arr[i].x;
				ysum -= arr[i].y;
			}
		}
		if ((unsigned long long)xsum * xsum + (unsigned long long)ysum * ysum < answer) {
			answer = (unsigned long long)xsum * xsum + (unsigned long long)ysum * ysum;
		}
	}
	else {
		for (int i = cur; i <= n - remain; i++) {
			visit[i] = true;
			func(arr, visit, i + 1, remain - 1, n, answer);
			visit[i] = false;
		}
	}
}