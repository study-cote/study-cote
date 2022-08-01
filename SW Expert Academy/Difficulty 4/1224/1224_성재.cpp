#include <iostream>
#include <string>

struct StackOp {
	char data;
	StackOp* next;

	StackOp(char, StackOp*);
};

struct StackNum {
	int data;
	StackNum* next;

	StackNum(int, StackNum*);
};

char popOp(StackOp*&);
int popNum(StackNum*&);

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int len;
		std::string str;
		std::cin >> len >> str;
		StackOp* opTop = NULL;
		StackNum* numTop = NULL;
		for (int i = 0; i < len; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				numTop = new StackNum(str[i] - '0', numTop);
			}
			else {
				int a, b;
				char op;
				switch (str[i]) {
				case '+':
					while (opTop && opTop->data != '(') {
						b = popNum(numTop);
						a = popNum(numTop);
						op = popOp(opTop);
						if (op == '+') {
							numTop = new StackNum(a + b, numTop);
						}
						else {
							numTop = new StackNum(a * b, numTop);
						}
					}
					opTop = new StackOp(str[i], opTop);
					break;
				case '*':
					while (opTop && opTop->data != '(' && opTop->data != '+') {
						b = popNum(numTop);
						a = popNum(numTop);
						op = popOp(opTop);
						numTop = new StackNum(a * b, numTop);
					}
					opTop = new StackOp(str[i], opTop);
					break;
				case '(':
					opTop = new StackOp(str[i], opTop);
					break;
				case ')':
					while (opTop && opTop->data != '(') {
						b = popNum(numTop);
						a = popNum(numTop);
						op = popOp(opTop);
						if (op == '+') {
							numTop = new StackNum(a + b, numTop);
						}
						else {
							numTop = new StackNum(a * b, numTop);
						}
					}
					op = popOp(opTop);
					break;
				}
			}
		}
		while (opTop) {
			char op = popOp(opTop);
			if (op == '+' || op == '*') {
				int b = popNum(numTop);
				int a = popNum(numTop);
				if (op == '+') {
					numTop = new StackNum(a + b, numTop);
				}
				else {
					numTop = new StackNum(a * b, numTop);
				}
			}
		}
		int answer = popNum(numTop);
		std::cout << '#' << testcase << ' ' << answer << '\n';
	}

	return 0;
}

StackOp::StackOp(char ch, StackOp* ptr) : data(ch), next(ptr) {

}

StackNum::StackNum(int n, StackNum* ptr) : data(n), next(ptr) {

}

char popOp(StackOp*& ptr) {
	StackOp* temp = ptr;
	char retVal = ptr->data;
	ptr = ptr->next;
	delete temp;
	return retVal;
}

int popNum(StackNum*& ptr) {
	StackNum* temp = ptr;
	int retVal = ptr->data;
	ptr = ptr->next;
	delete temp;
	return retVal;
}