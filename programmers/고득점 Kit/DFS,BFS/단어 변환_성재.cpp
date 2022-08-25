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
    string word;
    List* child;

    Element(string);
    ~Element();
};

int bfs(Element**, int, int);

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    Element** node = new Element * [words.size() + 1];
    int len = begin.size(), start = words.size(), end = -1;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].compare(target) == 0) {
            end = i;
        }
        node[i] = new Element(words[i]);
        for (int j = 0; j < i; j++) {
            int count = 0;
            for (int k = 0; k < len; k++) {
                if (words[i][k] == words[j][k]) {
                    count++;
                }
            }
            if (count == len - 1) {
                node[i]->child = new List(j, node[i]->child);
                node[j]->child = new List(i, node[j]->child);
            }
        }
    }
    node[start] = new Element(begin);
    for (int i = 0; i < start; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (begin[j] == words[i][j]) {
                count++;
            }
        }
        if (count == len - 1) {
            node[start]->child = new List(i, node[start]->child);
        }
    }

    if (end >= 0) {
        answer = bfs(node, start, end);
    }

    for (int i = 0; i <= start; i++) {
        delete node[i];
    }
    delete[] node;

    return answer;
}

List::List(int d, List* ptr) : data(d), next(ptr) {
    
}

List::~List() {
    if (next) {
        delete next;
    }
}

Element::Element(string str) : word(str), child(NULL) {

}

Element::~Element() {
    if (child) {
        delete child;
    }
}

int bfs(Element** node, int start, int end) {
    int size = start + 1;
    int* depth = new int[size];
    bool* visit = new bool[size];
    for (int i = 0; i < size; i++) {
        visit[i] = false;
    }
    visit[start] = true;
    depth[start] = 0;
    depth[end] = 0;

    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (List* search = node[cur]->child; search; search = search->next) {
            if (!visit[search->data]) {
                visit[search->data] = true;
                depth[search->data] = depth[cur] + 1;
                Q.push(search->data);
            }
        }
    }

    int retVal = depth[end];

    delete[] depth, visit;

    return retVal;
}