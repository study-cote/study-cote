#include <iostream>
#include <vector>

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		bool visit[10001];
		std::vector<int> arr;
		for (int i = 0; i < 10001; i++) {
			visit[i] = false;
		}
		arr.push_back(0);
		for (int i = 0; i < n; i++) {
			int temp;
			std::cin >> temp;
			int size = arr.size();
			for (int i = 0; i < size; i++) {
				if (!visit[arr[i] + temp]) {
					visit[arr[i] + temp] = true;
					arr.push_back(arr[i] + temp);
				}
			}
		}
		std::cout << '#' << testcase << ' ' << arr.size() << '\n';
	}

	return 0;
}