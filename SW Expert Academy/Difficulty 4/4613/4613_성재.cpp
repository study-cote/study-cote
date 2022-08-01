#include <iostream>
#include <string>

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n, m;
		std::cin >> n >> m;
		std::string str;
		int* white, * blue, * red;
		white = new int[n];
		blue = new int[n];
		red = new int[n];
		int answer = 0;
		std::cin >> str;
		for (int i = 0; i < m; i++) {
			if (str[i] != 'W') {
				answer++;
			}
		}
		for (int i = 1; i < n - 1; i++) {
			white[i] = 0;
			blue[i] = 0;
			red[i] = 0;
			std::cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'W') {
					blue[i]++;
					red[i]++;
				}
				else if (str[j] == 'B') {
					white[i]++;
					red[i]++;
				}
				else {
					white[i]++;
					blue[i]++;
				}
			}
		}
		std::cin >> str;
		for (int i = 0; i < m; i++) {
			if (str[i] != 'R') {
				answer++;
			}
		}
		for (int i = 1; i < n - 1; i++) {
			answer += blue[i];
		}
		int whiteSum = 0, blueSum = 0, index = 0;
		for (int i = 1; i < n - 2; i++) {
			whiteSum += white[i];
			blueSum += blue[i];
			if (whiteSum < blueSum) {
				answer = answer - blueSum + whiteSum;
				index = i;
				whiteSum = 0;
				blueSum = 0;
			}
		}
		int redSum = 0;
		blueSum = 0;
		for (int i = n - 2; i > index; i--) {
			redSum += red[i];
			blueSum += blue[i];
			if (redSum < blueSum) {
				answer = answer - blueSum + redSum;
				redSum = 0;
				blueSum = 0;
			}
		}
		for (int i = index; i > 0; i--) {
			redSum += red[i];
			blueSum += white[i];
			if (redSum < blueSum) {
				answer = answer - blueSum + redSum;
				redSum = 0;
				blueSum = 0;
			}
		}

		std::cout << '#' << testcase << ' ' << answer << '\n';

		delete[] white, blue, red;
	}

	return 0;
}