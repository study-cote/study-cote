#include <iostream>
#include <queue>

struct Element {
	int a, b;
	long long distance;

	Element();
	Element(int, int, long long);
	bool operator<(const Element& e) const;
};

int main(void) {
	int t;

	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		long long* x = new long long[n];
		long long* y = new long long[n];
		bool* visit = new bool[n];
		for (int i = 0; i < n; i++) {
			std::cin >> x[i];
			visit[i] = false;
		}
		for (int i = 0; i < n; i++) {
			std::cin >> y[i];
		}
		double e;
		std::cin >> e;

		int count = 1;
		visit[0] = true;
		long long answer = 0;
		std::priority_queue<Element> PQ;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				long long dis = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
				Element temp(0, i, dis);
				PQ.push(temp);
			}
		}
		while (count < n) {
			Element min;
			while (true) {
				min = PQ.top();
				PQ.pop();
				if (!visit[min.b]) {
					break;
				}
			}
			count++;
			answer += min.distance;
			visit[min.b] = true;
			for (int i = 0; i < n; i++) {
				if (!visit[i]) {
					long long dis = (x[i] - x[min.b]) * (x[i] - x[min.b]) + (y[i] - y[min.b]) * (y[i] - y[min.b]);
					Element temp(min.b, i, dis);
					PQ.push(temp);
				}
			}
		}
		std::cout << std::fixed;
		std::cout.precision(0);
		std::cout << '#' << testcase << ' ' << e * answer << '\n';
		delete[] x, y, visit;
	}

	return 0;
}

Element::Element() {

}

Element::Element(int s, int d, long long dis) : a(s), b(d), distance(dis) {

}

bool Element::operator<(const Element& e) const {
	return this->distance > e.distance;
}