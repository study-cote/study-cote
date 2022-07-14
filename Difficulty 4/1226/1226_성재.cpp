#include <iostream>
#include <string>

bool hasRoad(int**, bool**, int, int);

int main(void) {
	for (int testcase = 0; testcase < 10; testcase++) {
		int t;
		std::cin >> t;
		int** map = new int* [16];
		bool** visit = new bool* [16];
		std::string str;
		for (int i = 0; i < 16; i++) {
			map[i] = new int[16];
			visit[i] = new bool[16];
			std::cin >> str;
			for (int j = 0; j < 16; j++) {
				map[i][j] = str[j] - '0';
				visit[i][j] = false;
			}
		}
		int startX, startY;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				if (map[i][j] == 2) {
					startX = i;
					startY = j;
					break;
				}
			}
		}
		std::cout << '#' << t << ' ';
		if (hasRoad(map, visit, startX, startY)) {
			std::cout << 1;
		}
		else {
			std::cout << 0;
		}
		std::cout << '\n';

		for (int i = 0; i < 16; i++) {
			delete[] map[i], visit[i];
		}
		delete[] map, visit;
	}

	return 0;
}

bool hasRoad(int** map, bool** visit, int x, int y) {
	if (map[x][y] == 3) {
		return true;
	}
	visit[x][y] = true;
	if (x + 1 < 16 && map[x + 1][y] != 1 && !visit[x + 1][y]) {
		if (hasRoad(map, visit, x + 1, y)) {
			return true;
		}
	}
	if (y + 1 < 16 && map[x][y + 1] != 1 && !visit[x][y + 1]) {
		if (hasRoad(map, visit, x, y + 1)) {
			return true;
		}
	}
	if (x - 1 >= 0 && map[x - 1][y] != 1 && !visit[x - 1][y]) {
		if (hasRoad(map, visit, x - 1, y)) {
			return true;
		}
	}
	if (y - 1 >= 0 && map[x][y - 1] != 1 && !visit[x][y - 1]) {
		if (hasRoad(map, visit, x, y - 1)) {
			return true;
		}
	}
	return false;
}