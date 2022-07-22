#include <iostream>

void search(int*&, int, int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n, m;
		std::cin >> n >> m;
		int* parent = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			parent[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			std::cin >> a >> b;
			search(parent, a, b);
		}
		bool* visit = new bool[n + 1];
		for (int i = 1; i <= n; i++) {
			visit[i] = false;
		}
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			int j;
			for (j = i; parent[j]; j = parent[j]);
			if (!visit[j]) {
				visit[j] = true;
				answer++;
			}
		}

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] parent, visit;
	}

	return 0;
}

void search(int*& parent, int a, int b) {
	int aP, bP;
	for (aP = a; parent[aP]; aP = parent[aP]);
	for (bP = b; parent[bP]; bP = parent[bP]);
	if (aP != bP) {
		parent[bP] = aP;
	}
}