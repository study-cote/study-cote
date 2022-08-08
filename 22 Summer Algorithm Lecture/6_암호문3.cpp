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

// 앞에서부터 x의 위치 바로 다음에 y개 숫자 삽입, s는 삽입할 숫자
void insertNode(int data, int x, int cnt) {
    Node* n = getNode(data);
    Node* prev = head;
    int idx = 0;

    while (prev->next != nullptr && x != idx) {
        prev = prev->next;
        idx++;
    }

    while (cnt--) {
        if (prev->next != nullptr)
            prev = prev->next;
    }

    n->next = prev->next;
    prev->next = n;

    return;
}

// 앞에서부터 x의 위치 바로 다음부터 y개 숫자 삭제
void deleteNode(int x, int y) {
    int cnt = 0;
    int idx = 0;

    Node* prev = head;
    while (prev->next != nullptr && idx != x) {
        prev = prev->next;
        idx++;
    }

    Node* next = prev;
    while (next->next != nullptr && cnt != y) {
        next = next->next;
    }

    if (cnt != y) {
        prev->next = next->next;
    }

    return;
}

// 암호문 맨 뒤에 y개의 숫자 덧붙임. s는 덧붙일 숫자
void appendNode(int data) {
    Node* n = getNode(data);
    Node* prev = head;

    // find last node
    while (prev->next != nullptr)
        prev = prev->next;
    
    // addition
    prev->next = n;
    return;
}

void printNode(int t) {
    int cnt =0;
    Node* prev = head->next;

    cout << "#" << t << " ";
    while(prev->next != nullptr && cnt != 10) {
        cnt++;
        cout << prev->data << " ";
        prev = prev->next;
    }

    return;
}

int main(void) {
    for (int t=1; t<=10; t++) {
        int n, crypt, cmd_num, x, y;
        char cmd;

        // init
        head = getNode(0);
        
        // get original crypt
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> crypt;
            appendNode(crypt);
        }

        // get cmd
        cin >> cmd_num;
        for (int i=0; i<cmd_num; i++) {
            cin >> cmd;

            switch (cmd)
            {
            case 'I':
                cin >> x >> y;
                for (int j=0; j<y; j++) {
                    cin >> crypt; // s
                    insertNode(crypt, x, j);
                }
                break;

            case 'D':
                cin >> x >> y;
                deleteNode(x, y);
                break;

            case 'A':
                cin >> y;
                for (int j=0; j<y; j++) {
                    cin >> crypt;
                    appendNode(crypt);
                }
                break;
                        
            default:
                break;
            }
        }

        printNode(t);
        cout << endl;
    }
    return 0;
}