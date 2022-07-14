#include <iostream>

struct Node {
	int depth;
	Node *num[10];

	Node(int);
};

void search(int**, Node*&, int, int, int);
int answer(Node*);

int main(void) {
	int t;
	
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int** arr = new int* [4];
		for (int i = 0; i < 4; i++) {
			arr[i] = new int[4];
			for (int j = 0; j < 4; j++) {
				std::cin >> arr[i][j];
			}
		}
		Node* root = new Node(0);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				search(arr, root->num[arr[i][j]], 0, i, j);
			}
		}
		std::cout << '#' << testcase << ' ' << answer(root) << '\n';
		
		for (int i = 0; i < 4; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	return 0;
}

Node::Node(int d) : depth(d) {
	for (int i = 0; i < 10; i++) {
		num[i] = NULL;
	}
}

void search(int** arr, Node*& ptr, int cur, int r, int c) {
	if (cur < 7) {
		if (!ptr) {
			ptr = new Node(cur);
		}
		if (r + 1 < 4) {
			search(arr, ptr->num[arr[r + 1][c]], cur + 1, r + 1, c);
		}
		if (c + 1 < 4) {
			search(arr, ptr->num[arr[r][c + 1]], cur + 1, r, c + 1);
		}
		if (r - 1 >= 0) {
			search(arr, ptr->num[arr[r - 1][c]], cur + 1, r - 1, c);
		}
		if (c - 1 >= 0) {
			search(arr, ptr->num[arr[r][c - 1]], cur + 1, r, c - 1);
		}
	}
}

int answer(Node* ptr) {
	if (ptr) {
		if (ptr->depth == 6) {
			delete ptr;
			return 1;
		}
		int count = 0;
		for (int i = 0; i < 10; i++) {
			count += answer(ptr->num[i]);
		}
		return count;
	}
	else {
		return 0;
	}
}