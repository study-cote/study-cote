#include <string>
#include <vector>
#include <queue>

using namespace std;

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

struct Element {
    int data, depth;
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    List** node = new List * [n + 1];
    bool* visit = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        node[i] = NULL;
        visit[i] = false;
    }
    for (vector<vector<int>>::iterator i = edge.begin(); i != edge.end(); i++) {
        node[(*i)[0]] = new List((*i)[1], node[(*i)[0]]);
        node[(*i)[1]] = new List((*i)[0], node[(*i)[1]]);
    }
    Element cur = { 1,1 };
    queue<Element> Q;
    Q.push(cur);
    visit[1] = true;
    int max = 0;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        if (cur.depth > max) {
            max = cur.depth;
            answer = 1;
        }
        else {
            answer++;
        }
        for (List* ptr = node[cur.data]; ptr; ptr = ptr->next) {
            if (!visit[ptr->data]) {
                visit[ptr->data] = true;
                Element temp = { ptr->data, cur.depth + 1 };
                Q.push(temp);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (node[i]) {
            delete node[i];
        }
    }
    delete[] node, visit;

    return answer;
}

List::List(int n, List* ptr) : data(n), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}