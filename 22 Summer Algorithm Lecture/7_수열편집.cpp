#define MAX_NODE 100000
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void appendNode(int data) {
    Node* n = getNode(data);
    Node* prev = head;

    while (prev->next != nullptr)
        prev = prev->next;
    
    prev->next = n;

    return;
}

void insertNode(int data, int idx) {
    Node* n = getNode(data);
    Node* prev = head;
    int cnt = -1;

    while (prev->next != nullptr && cnt != idx-1) {
        prev = prev->next;
        cnt++;
    }

    n->next = prev->next;
    prev->next = n;

    return;
}

void deleteNode(int idx) {
    Node* prev = head;
    int cnt = -1;

    while(prev->next != nullptr && cnt != idx-1) {
        prev = prev->next;
        cnt++;
    }

    Node* next = prev->next->next;
    prev->next = next;

    return;
}

// change data in node[a] to  b
void changeNode(int idx, int data) {
    Node* prev = head;
    int cnt = -1;

    while (prev->next != nullptr && cnt != idx) {
        prev = prev->next;
        cnt++;
    }

    prev->data = data;

    return;
}

// void printAll() {
//     Node* prev= head->next;
//     while(prev != nullptr) {
//         cout << prev->data << " ";
//         prev = prev->next;
//     }
//     cout << endl;
//     return;
// }

void printNode(int index) {
    Node* prev = head;
    int cnt = -1;

    while(prev->next != nullptr && cnt != index) {
        prev = prev->next;
        cnt++;
    }

    if (cnt!=index) {
        cout << "-1" << endl;
    }
    else {
        cout << prev->data << endl;
    }
    
    return;
}

int main(void) {
    int test_case;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        // 수열의 길이 n, 추가 횟수 m, 출력할 인덱스 번호 l
        int n, m, l, num, idx;
        cin >> n >> m >> l;

        head = getNode(0); // init

        // get sequence of length n
        for (int i=0; i<n; i++) {
            cin >> num;
            appendNode(num);
        }

        char cmd;
        for (int i=0; i<m; i++) {
            cin >> cmd;

            switch (cmd){
                case 'I':
                    cin >> idx >> num;
                    insertNode(num, idx);
                    break;
                case 'D':
                    cin >> idx;
                    deleteNode(idx);
                    break;
                case 'C':
                    cin >> idx >> num;
                    changeNode(idx, num);
                    break;
                default:
                    break;
            }

            //printAll();
        }

        cout << "#" << t << " ";
        printNode(l);
    }

    return 0;
}