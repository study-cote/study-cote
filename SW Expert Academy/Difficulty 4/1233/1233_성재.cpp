#include <iostream>

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int n;
		std::cin >> n;
		int a, b, c;
		char ch;
		if (n % 2) {
			bool valid = true;
			for (int i = 0; i < n / 2; i++) {
				std::cin >> a >> ch >> b >> c;
				if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
					valid = false;
				}
			}
			for (int i = n / 2; i < n; i++) {
				std::cin >> a >> ch;
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
					valid = false;
				}
			}
			std::cout << '#' << testcase << ' ';
			if (valid) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
		else {
			for (int i = 0; i < n / 2 - 1; i++) {
				std::cin >> a >> ch >> b >> c;
			}
			std::cin >> a >> ch >> b;
			for (int i = n / 2; i < n; i++) {
				std::cin >> a >> ch;
			}
			std::cout << '#' << testcase << ' ' << "0\n";
		}
	}
	
	return 0;
}