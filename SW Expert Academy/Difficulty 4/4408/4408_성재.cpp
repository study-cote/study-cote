#include <iostream>
#include <queue>

struct Room {
	int start, end, dis;

	Room(int, int, int);
	bool operator<(const Room& r) const;
};

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		std::cin >> n;
		int a, b, dis;
		std::priority_queue<Room> PQ;
		for (int i = 0; i < n; i++) {
			std::cin >> a >> b;
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			dis = b - a;
			Room temp(a, b, dis);
			PQ.push(temp);
		}
		std::queue<Room> Q;
		while (!PQ.empty()) {
			Q.push(PQ.top());
			PQ.pop();
		}
		int trail, count = 0;
		while (!Q.empty()) {
			count++;
			trail = -1;
			int size = Q.size();
			for (int i = 0; i < size; i++) {
				Room temp = Q.front();
				Q.pop();
				if (temp.start <= trail) {
					Q.push(temp);
				}
				else {
					trail = temp.end;
				}
			}
		}
		std::cout << '#' << testcase << ' ' << count << '\n';
	}

	return 0;
}

Room::Room(int s, int e, int d) : start(s), end(e), dis(d) {

}

bool Room::operator<(const Room& r) const {
	if (this->start == r.start) {
		return this->dis > r.dis;
	}
	else {
		return this->start > r.start;
	}
}