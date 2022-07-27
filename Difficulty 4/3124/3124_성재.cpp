#include <iostream>
#include <queue>

struct Node {
	int num;
	long long weight;
	Node* next;

	Node(int, long long, Node*);
	~Node();
};

struct Element {
	int start, end;
	long long weight;

	Element();
	Element(int, int, long long);
	bool operator<(const Element& e) const;
};

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int v, e;
		std::cin >> v >> e;
		bool* visit = new bool[v + 1];
		Node** head = new Node * [v + 1];
		for (int i = 1; i <= v; i++) {
			visit[i] = false;
			head[i] = NULL;
		}
		for (int i = 0; i < e; i++) {
			int a, b;
			long long w;
			std::cin >> a >> b >> w;
			head[a] = new Node(b, w, head[a]);
			head[b] = new Node(a, w, head[b]);
		}
		std::priority_queue<Element> PQ;
		visit[1] = true;
		int count = 1;
		long long answer = 0;
		for (Node* search = head[1]; search; search = search->next) {
			if (!visit[search->num]) {
				Element temp(1, search->num, search->weight);
				PQ.push(temp);
			}
		}
		while (count < v) {
			Element temp;
			do {
				temp = PQ.top();
				PQ.pop();
			} while (visit[temp.end]);
			visit[temp.end] = true;
			answer += temp.weight;
			count++;
			for (Node* search = head[temp.end]; search; search = search->next) {
				if (!visit[search->num]) {
					Element elem(temp.end, search->num, search->weight);
					PQ.push(elem);
				}
			}
		}

		std::cout << '#' << testcase << ' ' << answer << '\n';

		for (int i = 1; i <= v; i++) {
			if (head[i]) {
				delete head[i];
			}
		}
		delete[] visit, head;
	}

	return 0;
}

Node::Node(int n, long long w, Node* ptr) : num(n), weight(w), next(ptr) {

}

Node::~Node() {
	if (next) {
		delete next;
	}
}

Element::Element() {

}

Element::Element(int a, int b, long long w) : start(a), end(b), weight(w) {

}

bool Element::operator<(const Element& e) const {
	return this->weight > e.weight;
}