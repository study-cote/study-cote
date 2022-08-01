#include <iostream>

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		unsigned long long n;
		scanf("%llu", &n);        // cin으로 하면 시간초과
		int count = 0;
		for (unsigned long long temp = 1ull; temp <= n; temp = (temp << 1) + 1, count++);
		unsigned long long limit = 1ull;
		bool aliceWin;
		if (count % 2) {
			for (int i = 0; i < count; i++) {
				if (i % 2) {
					limit = (limit << 1) + 1;
				}
				else {
					limit <<= 1;
				}
			}
			if (n < limit) {
				aliceWin = false;
			}
			else {
				aliceWin = true;
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (i % 2) {
					limit <<= 1;
				}
				else {
					limit = (limit << 1) + 1;
				}
			}
			if (n < limit) {
				aliceWin = true;
			}
			else {
				aliceWin = false;
			}
		}
		std::cout << '#' << testcase << ' ';
		if (aliceWin) {
			std::cout << "Alice\n";
		}
		else {
			std::cout << "Bob\n";
		}
	}

	return 0;
}