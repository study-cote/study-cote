#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Child {
    int data;
    Child* next;

    Child(int, Child*);
    ~Child();
};

struct List {
    int count;
    Child* child;

    List();
    ~List();
};

void sumCount(List*, int);
void func(List*, int, int, int&);

int solution(int n, vector<vector<int>> wires) {
    int answer = n + 1;

    List* list = new List[n + 1];
    bool* visit = new bool[n + 1];
    visit[1] = true;
    for (int i = 2; i <= n; i++) {
        visit[i] = false;
    }
    queue<vector<int>> Q;
    for (int i = 0; i < wires.size(); i++) {
        Q.push(wires[i]);
    }
    while (!Q.empty()) {
        int a = Q.front()[0], b = Q.front()[1];
        if (visit[a] || visit[b]) {
            if (visit[a]) {
                list[a].child = new Child(b, list[a].child);
                visit[b] = true;
            }
            else {
                list[b].child = new Child(a, list[b].child);
                visit[a] = true;
            }
        }
        else {
            Q.push(Q.front());
        }
        Q.pop();
    }
    sumCount(list, 1);
    func(list, 1, list[1].count, answer);
    
    delete[] list, visit;

    return answer;
}

Child::Child(int d, Child* ptr) : data(d), next(ptr) {

}

Child::~Child() {
    if (next) {
        delete next;
    }
}

List::List() : count(1), child(NULL) {

}

List::~List() {
    if (child) {
        delete child;
    }
}

void sumCount(List* ptr, int cur) {
    for (Child* search = ptr[cur].child; search; search = search->next) {
        sumCount(ptr, search->data);
        ptr[cur].count += ptr[search->data].count;
    }
}

void func(List* ptr, int cur, int sum, int& answer) {
    for (Child* search = ptr[cur].child; search; search = search->next) {
        if (abs(sum - 2 * ptr[search->data].count) < answer) {
            answer = abs(sum - 2 * ptr[search->data].count);
        }
        func(ptr, search->data, sum, answer);
    }
}