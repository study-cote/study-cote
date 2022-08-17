#include <string>
#include <vector>
#include <queue>

using namespace std;

struct List {
    int data, weight;
    List* next;

    List(int, int, List*);
    ~List();
};

struct Element {
    int data, weigth;

    bool operator<(const Element&) const;
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    List** bridge = new List * [n];
    bool* visit = new bool[n];
    for (int i = 0; i < n; i++) {
        bridge[i] = NULL;
        visit[i] = false;
    }
    for (int i = 0; i < costs.size(); i++) {
        bridge[costs[i][0]] = new List(costs[i][1], costs[i][2], bridge[costs[i][0]]);
        bridge[costs[i][1]] = new List(costs[i][0], costs[i][2], bridge[costs[i][1]]);
    }
    visit[0] = true;
    int count = n - 1;
    priority_queue<Element> PQ;
    for (List* search = bridge[0]; search; search = search->next) {
        Element temp = { search->data, search->weight };
        PQ.push(temp);
    }
    while (count) {
        Element min;
        do {
            min = PQ.top();
            PQ.pop();
        } while (visit[min.data]);
        visit[min.data] = true;
        answer += min.weigth;
        count--;
        for (List* search = bridge[min.data]; search; search = search->next) {
            Element temp = { search->data, search->weight };
            PQ.push(temp);
        }
    }

    for (int i = 0; i < n; i++) {
        if (bridge[i]) {
            delete bridge[i];
        }
    }
    delete[] bridge, visit;

    return answer;
}

List::List(int d, int w, List* ptr) : data(d), weight(w), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

bool Element::operator<(const Element& e) const {
    return this->weigth > e.weigth;
}