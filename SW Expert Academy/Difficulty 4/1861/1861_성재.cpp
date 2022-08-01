#include <iostream>

struct Stack {
	int row, col;
	Stack* next;

	Stack(int, int, Stack*);
};

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		int** arr = new int* [n];
		int** dis = new int* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
			dis[i] = new int[n];
			for (int j = 0; j < n; j++) {
				std::cin >> arr[i][j];
				dis[i][j] = -1;
			}
		}
		int max = -1, answer = n * n + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] < 0) {
					int r = i, c = j;
					Stack* up = new Stack(r, c, NULL);
					bool hasRoad = true;
					int upCount = 0;
					while (hasRoad) {
						upCount++;
						hasRoad = false;
						if (r + 1 < n && arr[r + 1][c] == arr[r][c] + 1) {
							hasRoad = true;
							up = new Stack(r + 1, c, up);
							r = r + 1;
						}
						else if (c + 1 < n && arr[r][c + 1] == arr[r][c] + 1) {
							hasRoad = true;
							up = new Stack(r, c + 1, up);
							c = c + 1;
						}
						else if (r - 1 >= 0 && arr[r - 1][c] == arr[r][c] + 1) {
							hasRoad = true;
							up = new Stack(r - 1, c, up);
							r = r - 1;
						}
						else if (c - 1 >= 0 && arr[r][c - 1] == arr[r][c] + 1) {
							hasRoad = true;
							up = new Stack(r, c - 1, up);
							c = c - 1;
						}
					}
					r = i;
					c = j;
					Stack* down = new Stack(r, c, NULL);
					hasRoad = true;
					int downCount = 0;
					while (hasRoad) {
						downCount++;
						hasRoad = false;
						if (r + 1 < n && arr[r + 1][c] == arr[r][c] - 1) {
							hasRoad = true;
							down = new Stack(r + 1, c, down);
							r = r + 1;
						}
						else if (c + 1 < n && arr[r][c + 1] == arr[r][c] - 1) {
							hasRoad = true;
							down = new Stack(r, c + 1, down);
							c = c + 1;
						}
						else if (r - 1 >= 0 && arr[r - 1][c] == arr[r][c] - 1) {
							hasRoad = true;
							down = new Stack(r - 1, c, down);
							r = r - 1;
						}
						else if (c - 1 >= 0 && arr[r][c - 1] == arr[r][c] - 1) {
							hasRoad = true;
							down = new Stack(r, c - 1, down);
							c = c - 1;
						}
					}
					upCount = upCount + downCount - 1;
					downCount = upCount;
					for (; up; upCount--) {
						r = up->row;
						c = up->col;
						Stack* temp = up;
						up = up->next;
						delete temp;
						if (dis[r][c] < upCount) {
							dis[r][c] = upCount;
						}
						else {
							break;
						}
					}
					while (up) {
						Stack* temp = up;
						up = up->next;
						delete temp;
					}
					for (; down; downCount--) {
						r = down->row;
						c = down->col;
						Stack* temp = down;
						down = down->next;
						delete temp;
						if (dis[r][c] < downCount) {
							dis[r][c] = downCount;
						}
						else {
							break;
						}
					}
					while (down) {
						Stack* temp = down;
						down = down->next;
						delete temp;
					}
				}
				if (dis[i][j] > max) {
					max = dis[i][j];
					answer = arr[i][j];
				}
				else if (dis[i][j] == max && arr[i][j] < answer) {
					answer = arr[i][j];
				}
			}
		}
		std::cout << '#' << testcase << ' ' << answer << ' ' << max << '\n';
		
		for (int i = 0; i < n; i++) {
			delete[] arr[i], dis[i];
		}
		delete[] arr, dis;
	}

	return 0;
}

Stack::Stack(int r, int c, Stack* ptr) :row(r), col(c), next(ptr) {

}