#include <iostream>
#include <string>
#include <queue>

struct Element {
	int row, col, data;

	Element(int, int, int);
	bool operator<(const Element& e)const;
};

int main(void) {
	int t;

	std::cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;

		std::cin >> n;
		int** map = new int* [n];
		bool** visit = new bool* [n];
		std::string str;
		for (int j = 0; j < n; j++) {
			map[j] = new int[n];
			visit[j] = new bool[n];
			std::cin >> str;
			for (int k = 0; k < n; k++) {
				map[j][k] = str[k] - '0';
				visit[j][k] = false;
			}
		}
		
		std::priority_queue<Element> PQ;
		
		Element temp(0, 0, 0);
		PQ.push(temp);
		while (!PQ.empty()) {
			Element topElement = PQ.top();
			PQ.pop();
			if (topElement.row == n - 1 && topElement.col == n - 1) {
				std::cout << '#' << i << ' ' << topElement.data << '\n';
				break;
			}
			visit[topElement.row][topElement.col] = true;
			if (topElement.row - 1 >= 0 && !visit[topElement.row - 1][topElement.col]) {
				Element temp(topElement.row - 1, topElement.col, topElement.data + map[topElement.row - 1][topElement.col]);
				PQ.push(temp);
			}
			if (topElement.col - 1 >= 0 && !visit[topElement.row][topElement.col - 1]) {
				Element temp(topElement.row, topElement.col - 1, topElement.data + map[topElement.row][topElement.col - 1]);
				PQ.push(temp);
			}
			if (topElement.row + 1 < n && !visit[topElement.row + 1][topElement.col]) {
				Element temp(topElement.row + 1, topElement.col, topElement.data + map[topElement.row + 1][topElement.col]);
				PQ.push(temp);
			}
			if (topElement.col + 1 < n && !visit[topElement.row][topElement.col + 1]) {
				Element temp(topElement.row, topElement.col + 1, topElement.data + map[topElement.row][topElement.col + 1]);
				PQ.push(temp);
			}
		}

		for (int j = 0; j < n; j++) {
			delete[] map[j], visit[j];
		}
		delete[] map, visit;
	}

	return 0;
}

Element::Element(int r, int c, int d) : row(r), col(c), data(d) {

}

bool Element::operator<(const Element& e)const {
	return this->data > e.data;
}