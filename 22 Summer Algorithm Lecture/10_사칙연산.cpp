#include <iostream>
#include <string>

#define MAX_NODE 1000

using namespace std;

struct Node {
    string op;
    int left;
    int right;
};

Node node[MAX_NODE];

void newNode(int idx, string op, int left, int right) {
    node[idx].op = op;
    node[idx].left = left;
    node[idx].right = right;
}

string operation(int left, int right, string op) {
    if (op == "+")
        return to_string(left + right);
    if (op == "-")
        return to_string(left - right);
    if (op == "*")
        return to_string(left * right);
    if (op == "/")
        return to_string(left / right);
}

int postOrder(int idx) {
    if (node[idx].op == "+" ||  node[idx].op == "-" || node[idx].op == "*" || node[idx].op == "/") {
        int left = postOrder(node[idx].left);
        int right = postOrder(node[idx].right);
        node[idx].op = operation(left, right, node[idx].op);
    }
    return stoi(node[idx].op); // str to int
}

int main(void) {
    int n, idx, left, right;
    string op;

    for (int t=1; t<=10; t++) {
        cin >> n;

        for (int i=1; i<=n; i++) {
            left = 0, right = 0; // init

            cin >> idx >> op;

            if (op == "+" || op == "-" || op == "*" || op == "/")
                cin >> left >> right;

            newNode(idx, op, left, right);
        }

        cout << "#" << t << " " << postOrder(1) << endl;
    }
    return 0;
}