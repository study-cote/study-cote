#include <iostream>
#include <string>

struct Stack {
	int idx;
	Stack* next;

	Stack(int, Stack*);
};

int pop(Stack*&);

int main(void) {
	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		std::string str;
		std::cin >> str;
		Stack* top = NULL;
		int count = 0, answer = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				top = new Stack(i, top);
				count++;
			}
			else {
				int idx = pop(top);
				if (idx == i - 1) {
					count--;
					answer += count;
				}
				else {
					count--;
					answer++;
				}
			}
		}
		std::cout << '#' << testcase << ' ' << answer << '\n';
	}

	return 0;
}

Stack::Stack(int i, Stack* ptr) : idx(i), next(ptr) {

}

int pop(Stack*& ptr) {
	int retVal = ptr->idx;
	Stack* temp = ptr;
	ptr = ptr->next;
	delete temp;
	return retVal;
}