#define MAX_NODE 200
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int idx;
    char op;
    Node* left;
    Node* right;
};

Node node[MAX_NODE];
int n;
bool prev_flag = false, op_flag = false, ans = false;

void newNode(int idx, char op, int left, int right) {
    node[idx].idx = idx;
    node[idx].op = op;
    node[idx].left = &node[left];
    node[idx].right = &node[right];
    return;
}

void printInorder(int idx) {
    if (idx <= n) {
        printInorder(idx*2);

        prev_flag = op_flag;
        if (node[idx].op == '-' || node[idx].op == '+' || node[idx].op == '*' || node[idx].op == '/')
            op_flag = true;
        else op_flag = false;
        if ((prev_flag) && (op_flag))
            ans = true;
        
        printInorder(idx*2+1);
    }
}

int main(void) {
    int idx, left, right;
    char op;

    for (int t=1; t<=10; t++) {
        cin >> n;
        // init
        ans = false;

        // get input
        for (int i=1; i<=n; i++) {
            cin >> idx >> op;

            left = 0, right = 0;

            if (n%2 != 1 && i == n/2)
                cin >> left;
            else if (i <= n/2)
                cin >> left >> right;

            newNode(idx, op, left, right);  
        }

        printInorder(1);

        cout << "#" << t << " ";
        if (ans)
            cout << 0 << endl;
        else cout << 1 << endl;

    }

    return 0;
}