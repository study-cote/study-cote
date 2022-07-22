// 코드 더러워서 수정할 필요 있음,,
#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

// 초기화
void init()
{
    head = getNode(0);
    return;
}

// 맨 앞에 노드 추가
void addNode2Head(int data) 
{
    Node* n = getNode(data);
    
    // set node's ptrs
    n->prev = head;
    n->next = head->next;
    
    // link with next node
    if (head->next != nullptr)
        head->next->prev = n;

    // link with head
    head->next = n;

    return;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
    Node* n= getNode(data);
    Node* prev_node = head;

    // find last node
    while (prev_node->next != nullptr) {
        prev_node = prev_node->next;
    }

    // set pointer of current node
    n->prev = prev_node;

    // link with previous node
    prev_node->next = n;

    return;
}

// 이전 노드 next + 다음 노드 prev + 현재 노드 prev & next 고려해야 함!
// 지정된 순서 (num)에 노드 추가
void addNode2Num(int data, int num) 
{
    if (num == 1)
        addNode2Head(data);

    else {
        int idx = 1;

        Node* n = getNode(data);
        Node* prev_node = head;

        while (prev_node->next != nullptr && num != idx) {
            prev_node = prev_node->next;
            idx++;
        }

        n->prev = prev_node;
        n->next = prev_node->next;

        // link with next node
        if (prev_node->next != nullptr)
            prev_node->next->prev = n;

        // link with previous node
        prev_node->next = n;
    }

    return;
}

// data를 가진 노드의 순서 리턴
int findNode(int data) 
{
    int idx = 1;
    Node* prev_node = head;

    // find node with data
    while (prev_node->next != nullptr && prev_node->next->data != data) {
        prev_node = prev_node->next;
        idx++;
    }
    
    return idx;
}

// data를 가진 노드 삭제
void removeNode(int data) 
{
    Node* prev_node = head->next;

    // find node with data
    while (prev_node->next != nullptr && prev_node->data != data) {
        prev_node = prev_node->next;
    }

    // node to remove is not foud
    if (prev_node->next == nullptr && prev_node->data != data)
        return;

    if (prev_node->next != nullptr)
        prev_node->next->prev = prev_node->prev;

    prev_node->prev->next = prev_node->next;

    return;
}

// 노드의 data 정보를 차례대로 output[]에 저장하고 노드 갯수 리턴
int getList(int output[MAX_NODE]) 
{
    int idx=0;
    Node* prev_node = head->next;

    // until last-1 node
    while (prev_node->next != nullptr) {
        output[idx++] = prev_node->data;
        prev_node = prev_node->next;
    }

    // last node
    output[idx++] = prev_node->data;
    return idx;
}

// 노드의 data 정보를 역순으로 output[]에 저장하고 노드 갯수를 리턴
// 제대로 구현했는지 체크
int getReversedList(int output[MAX_NODE]) 
{
    int idx=0;
    Node* prev_node = head->next;

    // find last node
    while (prev_node->next != nullptr) {
        prev_node = prev_node->next;
    }

    // save data reversely
    for (prev_node; prev_node != head; prev_node = prev_node->prev) {
        output[idx++] = prev_node->data;
    }

    return idx;
}