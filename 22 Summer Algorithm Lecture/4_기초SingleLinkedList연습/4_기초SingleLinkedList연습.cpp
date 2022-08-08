#define MAX_NODE 10000

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
    n->next = head->next;
    head->next = n;
    return;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
    Node* n = getNode(data);
    Node* prev_node = head;

    // find last node
    while (prev_node->next != nullptr)
        prev_node = prev_node->next;
    
    // addition
    prev_node->next = n;
    return;
}

// 지정된 순서 (num)에 노드 추가
void addNode2Num(int data, int num) 
{
    int idx = 1;

    if (num == 1)
        addNode2Head(data);
    else {
        Node* n = getNode(data);
        Node* prev = head;

        while(prev->next != nullptr && idx != num) {
            prev = prev->next;
            idx++;
        }

        n->next = prev->next;
        prev->next = n;
    }
}

// 주어진 데이터 값 가진 노드 삭제
void removeNode(int data) 
{   
    Node* prev = head;
    
    // find the node has the data
    while (prev->next != nullptr && prev->next->data != data)
        prev = prev->next;
    
    // removal
    if (prev->next != nullptr) {
        prev->next = prev->next->next;
    }

    return;
}

// output[] 배열에 리스트 노드의 데이터 차례로 넣고, 총 노드 갯수 리턴
int getList(int output[MAX_NODE]) 
{
    Node *prev = head->next;
    int idx = 0;

    while(prev->next != nullptr) {
        output[idx++] = prev->data;
        prev = prev->next;
    }

    // last element
    output[idx++] = prev->data;

    return (idx);
}