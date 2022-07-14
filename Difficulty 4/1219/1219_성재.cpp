#include <iostream>

struct Stack {
	int data;
	Stack* next;

	Stack(int, Stack*);
};

bool dfs(int*, int*);
int pop(Stack*&);

int main(void) {
	for (int testcase = 0; testcase < 10; testcase++) {
		int t, n;
		std::cin >> t >> n;
		int* one = new int[100];
		int* two = new int[100];
		for (int i = 0; i < 100; i++) {
			one[i] = -1;
			two[i] = -1;
		}
		int a, b;
		for (int i = 0; i < n; i++) {
			std::cin >> a >> b;
			if (one[a] < 0) {
				one[a] = b;
			}
			else {
				two[a] = b;
			}
		}
		std::cout << '#' << t << ' ';
		if (dfs(one, two)) {
			std::cout << "1\n";
		}
		else {
			std::cout << "0\n";
		}
		delete[] one, two;
	}

	return 0;
}

Stack::Stack(int d, Stack* ptr) : data(d), next(ptr) {

}

bool dfs(int* arr1, int* arr2) {
	bool* visit = new bool[100];
	
	for (int i = 0; i < 100; i++) {
		visit[i] = false;
	}
	
	Stack* top = NULL;
	int cur = 0;
	top = new Stack(cur, top);
	while (top != NULL) {
		cur = pop(top);
		if (cur == 99) {
			while (top) {
				Stack* temp = top;
				top = top->next;
				delete temp;
			}
			delete[] visit;
			return true;
		}
		visit[cur] = true;
		if (arr1[cur] >= 0 && !visit[arr1[cur]]) {
			top = new Stack(cur, top);
			top = new Stack(arr1[cur], top);
		}
		else if (arr2[cur] >= 0 && !visit[arr2[cur]]) {
			top = new Stack(arr2[cur], top);
		}
	}

	delete[] visit;
	return false;
}

int pop(Stack*& ptr) {
	Stack* temp = ptr;
	int retVal = ptr->data;
	ptr = ptr->next;
	delete temp;
	return retVal;
}