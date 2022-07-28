#include <iostream>

struct Pos {
	int x, y;
};

void func(Pos*, bool*, int, int, int, int, unsigned long long&);

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
		func(arr, visit, 0, 0, 0, n, answer);

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] arr, visit;
	}

	return 0;
}

void func(Pos* arr, bool* visit, int xsum, int ysum, int count, int n, unsigned long long& answer) {
	if (count == n) {
		if ((unsigned long long)xsum * xsum + (unsigned long long)ysum * ysum < answer) {
			answer = (unsigned long long)xsum * xsum + (unsigned long long)ysum * ysum;
		}
	}
	else {
		int a = 0;
		for (; a < n - 1; a++) {
			if (!visit[a]) {
				break;
			}
		}
		visit[a] = true;
		for (int b = a + 1; b < n; b++) {
			if (!visit[b]) {
				visit[b] = true;
				func(arr, visit, xsum + (arr[a].x - arr[b].x), ysum + (arr[a].y - arr[b].y), count + 2, n, answer);
				func(arr, visit, xsum + (arr[b].x - arr[a].x), ysum + (arr[b].y - arr[a].y), count + 2, n, answer);
				visit[b] = false;
			}
		}
		visit[a] = false;
	}
}