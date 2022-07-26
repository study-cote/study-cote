#define MAX_NODE 100
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char alphabet;
    Node* left;
    Node* right;
};

Node node[MAX_NODE];
int n;

void newNode(int idx, char c, int left, int right) {
    node[idx].alphabet = c;
    node[idx].left = &node[left];
    node[idx].right = &node[right];
    return;
}

void printInorder(int idx) {
    if (idx <= n && idx > 0) {
        printInorder(idx * 2);
        cout << node[idx].alphabet;
        printInorder(idx * 2 + 1);
    }
    return;
}

int main(void) {
    
    for (int t=1; t<=10; t++) {
        int idx, left, right;
        char c;

        cin >> n;

        // get input
        for (int i=1; i<=n; i++) {
            cin >> idx;
            cin >> c;

            left = 0, right = 0;

            if (n%2 == 0 && i == n/2) {
                cin >> left;
            }
            else if (i <= n/2) {
                cin >> left;
                cin >> right;
            }

            newNode(idx, c, left, right);
        }

        cout << "#" << t << " ";
        printInorder(1);
        cout << endl;
    }

    return 0;
}