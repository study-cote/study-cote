#include <iostream>
#include <string>

struct Stack {
	char data;
	Stack* next;

	Stack(char, Stack*);
};

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int len;
		std::string str;
		
		std::cin >> len >> str;
		Stack* top = NULL;
		bool valid = true;
		for (int i = 0; valid && i < len; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
				top = new Stack(str[i], top);
			}
			else {
				if (!top) {
					valid = false;
				}
				else {
					char ch = top->data;
					Stack* temp = top;
					top = top->next;
					delete temp;
					switch (str[i]) {
					case ')':
						if (ch != '(') {
							valid = false;
						}
						break;
					case ']':
						if (ch != '[') {
							valid = false;
						}
						break;
					case '}':
						if (ch != '{') {
							valid = false;
						}
						break;
					case '>':
						if (ch != '<') {
							valid = false;
						}
						break;
					}
				}
			}
		}
		std::cout << '#' << testcase << ' ';
		if (valid) {
			std::cout << "1\n";
		}
		else {
			std::cout << "0\n";
		}
		while (top) {
			Stack* temp = top;
			top = top->next;
			delete temp;
		}
	}

	return 0;
}

Stack::Stack(char d, Stack* ptr) :data(d), next(ptr) {

}