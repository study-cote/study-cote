#include <iostream>

struct List {
	int data;
	List* next;

	List(int, List*);
	~List();
};

struct Visit {
	unsigned long long check[8];

	Visit();
};

void calculChild(List**, Visit*&, bool*&, int);
void calculParent(List**, Visit*&, bool*&, int);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int n, m;
		std::cin >> n >> m;
		List** child = new List * [n];
		List** parent = new List * [n];
		Visit* childCheck = new Visit[n];
		Visit* parentCheck = new Visit[n];
		bool* childStart = new bool[n];
		bool* parentStart = new bool[n];
		for (int i = 0; i < n; i++) {
			child[i] = NULL;
			parent[i] = NULL;
			childStart[i] = true;
			parentStart[i] = true;
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			std::cin >> a >> b;
			child[a - 1] = new List(b - 1, child[a - 1]);
			childStart[b - 1] = false;
			parent[b - 1] = new List(a - 1, parent[b - 1]);
			parentStart[a - 1] = false;
		}
		bool* childVisit = new bool[n];
		bool* parentVisit = new bool[n];
		for (int i = 0; i < n; i++) {
			childVisit[i] = false;
			parentVisit[i] = false;
		}
		for (int i = 0; i < n; i++) {
			if (childStart[i]) {
				calculChild(child, childCheck, childVisit, i);
			}
			if (parentStart[i]) {
				calculParent(parent, parentCheck, parentVisit, i);
			}
		}

		unsigned long long max = ~0ull, end;
		int answer = 0;
		if (n % 64 == 63) {
			end = max;
		}
		else {
			end = (1ull << (n % 64)) - 1;
		}
		for (int i = 0; i < n; i++) {
			parentCheck[i].check[i / 64] |= 1ull << (i % 64);
			int j = 0;
			for (; j < n / 64; j++) {
				if ((parentCheck[i].check[j] | childCheck[i].check[j]) != max) {
					break;
				}
			}
			if (j == n / 64 && (parentCheck[i].check[j] | childCheck[i].check[j]) == end) {
				answer++;
			}
		}

		std::cout << '#' << testcase << ' ' << answer << '\n';

		for (int i = 0; i < n; i++) {
			if (child[i]) {
				delete child[i];
			}
			if (parent[i]) {
				delete parent[i];
			}
		}
		delete[] child, parent, childCheck, parentCheck, childStart, parentStart, childVisit, parentVisit;
	}

	return 0;
}

List::List(int d, List* ptr) : data(d), next(ptr) {

}

List::~List() {
	if (next) {
		delete next;
	}
}

Visit::Visit() {
	for (int i = 0; i < 8; i++) {
		check[i] = 0;
	}
}

void calculChild(List** child, Visit*& childCheck, bool*& visit, int cur) {
	visit[cur] = true;
	int index = cur / 64;
	unsigned long long num = 1ull << (cur % 64);
	for (List* search = child[cur]; search; search = search->next) {
		if (!visit[search->data]) {
			calculChild(child, childCheck, visit, search->data);
		}
		for (int i = 0; i < 8; i++) {
			childCheck[cur].check[i] |= childCheck[search->data].check[i];
		}
		childCheck[cur].check[search->data / 64] |= 1ull << (search->data % 64);
	}
}

void calculParent(List** parent, Visit*& parentCheck, bool*& visit, int cur) {
	visit[cur] = true;
	int index = cur / 64;
	unsigned long long num = 1ull << (cur % 64);
	for (List* search = parent[cur]; search; search = search->next) {
		if (!visit[search->data]) {
			calculParent(parent, parentCheck, visit, search->data);
		}
		for (int i = 0; i < 8; i++) {
			parentCheck[cur].check[i] |= parentCheck[search->data].check[i];
		}
		parentCheck[cur].check[search->data / 64] |= 1ull << (search->data % 64);
	}
}