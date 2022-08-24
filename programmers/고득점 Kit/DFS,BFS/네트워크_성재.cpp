#include <string>
#include <vector>

using namespace std;

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

void func(List**, bool*&, int);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    List** list = new List * [n];
    bool* visit = new bool[n];
    for (int i = 0; i < computers.size(); i++) {
        list[i] = NULL;
        visit[i] = false;
        for (int j = 0; j < computers[i].size(); j++) {
            if (i != j && computers[i][j]) {
                list[i] = new List(j, list[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            func(list, visit, i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (list[i]) {
            delete list[i];
        }
    }
    delete[] list, visit;

    return answer;
}

List::List(int d, List* ptr) : data(d), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

void func(List** list, bool*& visit, int cur) {
    visit[cur] = true;
    for (List* search = list[cur]; search; search = search->next) {
        if (!visit[search->data]) {
            func(list, visit, search->data);
        }
    }
}