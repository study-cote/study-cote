#include <iostream>
#include <string>

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		std::string bin, tri;
		std::cin >> bin >> tri;
		unsigned long long* binArr = new unsigned long long[bin.length()];
		unsigned long long binSum = 0ull;
		for (int i = 0; i < (int)bin.length(); i++) {
			binSum *= 2;
			binSum += bin[i] - '0';
		}
		unsigned long long temp = 1ull;
		for (int i = bin.length() - 1; i >= 0; i--, temp *= 2) {
			binArr[i] = binSum - temp * (bin[i] - '0') + temp * ((bin[i] - '0' + 1) % 2);
		}
		unsigned long long triSum = 0ull;
		for (int i = 0; i < (int)tri.length(); i++) {
			triSum *= 3;
			triSum += tri[i] - '0';
		}
		temp = 1ull;
		unsigned long long answer = 0;
		for (int i = tri.length() - 1; !answer && i >= 0; i--, temp *= 3) {
			for (int j = 1; !answer && j <= 2; j++) {
				unsigned long long triTemp = triSum - temp * (tri[i] - '0') + temp * ((tri[i] - '0' + j) % 3);
				for (int k = 0; k < (int)bin.length(); k++) {
					if (binArr[k] == triTemp) {
						answer = triTemp;
						break;
					}
				}
			}
		}

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] binArr;
	}

	return 0;
}