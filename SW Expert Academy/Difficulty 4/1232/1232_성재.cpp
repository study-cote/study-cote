#include <iostream>
#include <string>

struct Node {
	enum type{Number, Operator} t;
	union {
		int num;
		char op;
	}data;
	int lchild, rchild;
};

double calcul(Node*, int);

int main(void) {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int n;
		std::cin >> n;
		Node* arr = new Node[n + 1];
		int a, b, c;
		std::string str;
		for (int i = 0; i < n; i++) {
			std::cin >> a >> str;
			if (str[0] >= '0' && str[0] <= '9') {
				arr[a].t = arr[a].Number;
				arr[a].data.num = std::stoi(str);
			}
			else {
				arr[a].t = arr[a].Operator;
				arr[a].data.op = str[0];
				std::cin >> b >> c;
				arr[a].lchild = b;
				arr[a].rchild = c;
			}
		}
		std::cout << '#' << testcase << ' ' << (int)calcul(arr, 1) << '\n';
		
		delete[] arr;
	}

	return 0;
}

double calcul(Node* arr, int cur) {
	if (arr[cur].t == arr[cur].Number) {
		return (double)arr[cur].data.num;
	}
	else {
		switch (arr[cur].data.op) {
		case '+':
			return calcul(arr, arr[cur].lchild) + calcul(arr, arr[cur].rchild);
			break;
		case '-':
			return calcul(arr, arr[cur].lchild) - calcul(arr, arr[cur].rchild);
			break;
		case '*':
			return calcul(arr, arr[cur].lchild) * calcul(arr, arr[cur].rchild);
			break;
		case '/':
			return calcul(arr, arr[cur].lchild) / calcul(arr, arr[cur].rchild);
			break;
		}
	}
}