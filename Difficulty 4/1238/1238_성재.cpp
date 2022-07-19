#include <iostream>
#include <queue>

struct List {
	int data;
	List* next;

	List(int, List*);
};

struct Element {
	int num, count;

	Element(int, int);
};

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int n, start;
		std::cin >> n >> start;
		int from, to;
		List** list = new List * [101];
		bool* visit = new bool[101];
		for (int i = 1; i <= 100; i++) {
			list[i] = NULL;
			visit[i] = false;
		}
		for (int i = 0; i < n / 2; i++) {
			std::cin >> from >> to;
			list[from] = new List(to, list[from]);
		}
		std::queue<Element> Q;
		Element temp(start, 0);
		Q.push(temp);
		visit[start] = true;
		int maxCount = -1, answer = -1;
		while (!Q.empty()) {
			int num = Q.front().num;
			int count = Q.front().count;
			if (count > maxCount) {
				maxCount = count;
				answer = num;
			}
			else if (count == maxCount && num > answer) {
				answer = num;
			}
			Q.pop();
			for (List* search = list[num]; search; search = search->next) {
				if (!visit[search->data]) {
					Element temp(search->data, count + 1);
					Q.push(temp);
					visit[search->data] = true;
				}
			}
		}
		std::cout << '#' << testcase << ' ' << answer << '\n';

		for (int i = 1; i < 101; i++) {
			for (List* ptr = list[i]; ptr;) {
				List* temp = ptr;
				ptr = ptr->next;
				delete temp;
			}
		}
		delete[] list, visit;
	}

	return 0;
}

List::List(int d, List* ptr) :data(d), next(ptr) {

}

Element::Element(int n, int c) : num(n), count(c) {

}