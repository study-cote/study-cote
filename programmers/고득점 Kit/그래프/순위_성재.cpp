#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Result {
    unsigned long long result[2];

    Result(int);

    Result operator|=(const Result&);
    Result operator&=(const Result&);
};

struct List {
    int data;
    List* next;

    List(int, List*);
    ~List();
};

struct Element {
    Result parent, child;
    List* plist, * clist;

    Element(int);
    ~Element();
};

void childSearch(Element**&, int, int);
void parentSearch(Element**&, int, int);
int count(Element**&, int);

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    Element** node = new Element * [n + 1];
    bool* pStart = new bool[n + 1];
    bool* cStart = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        node[i] = new Element(i);
        pStart[i] = true;
        cStart[i] = true;
    }
    for (vector<vector<int>>::iterator i = results.begin(); i != results.end(); i++) {
        node[(*i)[0]]->clist = new List((*i)[1], node[(*i)[0]]->clist);
        pStart[(*i)[1]] = false;
        node[(*i)[1]]->plist = new List((*i)[0], node[(*i)[1]]->plist);
        cStart[(*i)[0]] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (pStart[i]) {
            childSearch(node, i, n);
        }
        if (cStart[i]) {
            parentSearch(node, i, n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (count(node, i) == n) {
            answer++;
        }
    }

    for (int i = 1; i <= n; i++) {
        delete node[i];
    }
    delete[] node, pStart, cStart;

    return answer;
}

Result::Result(int n) {
    for (int i = 0; i < 2; i++) {
        result[i] = 0ull;
    }
    result[n / 64] = 1ull << (n % 64);
}

Result Result::operator|=(const Result& r) {
    this->result[0] |= r.result[0];
    this->result[1] |= r.result[1];
    return *this;
}

Result Result::operator&=(const Result& r) {
    this->result[0] &= r.result[0];
    this->result[1] &= r.result[1];
    return *this;
}

List::List(int n, List* ptr) : data(n), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

Element::Element(int n) : parent(n), child(n), plist(NULL), clist(NULL) {

}

Element::~Element() {
    if (plist) {
        delete plist;
    }
    if (clist) {
        delete clist;
    }
}

void childSearch(Element**& ptr, int cur, int n) {
    queue<int> q1, q2;
    bool* visit = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    q1.push(cur);
    while (!q1.empty()) {
        cur = q1.front();
        q1.pop();
        q2.push(cur);
        for (List* search = ptr[cur]->clist; search; search = search->next) {
            if (!visit[search->data]) {
                q1.push(search->data);
                visit[search->data] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    while (!q2.empty()) {
        cur = q2.front();
        q2.pop();
        List* search = ptr[cur]->clist;
        for (; search; search = search->next) {
            if (!visit[search->data]) {
                break;
            }
        }
        if (search) {
            q2.push(cur);
        }
        else {
            for (search = ptr[cur]->clist; search; search = search->next) {
                ptr[cur]->child |= ptr[search->data]->child;
            }
            visit[cur] = true;
        }
    }

    delete[] visit;
}

void parentSearch(Element**& ptr, int cur, int n) {
    queue<int> q1, q2;
    bool* visit = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    q1.push(cur);
    while (!q1.empty()) {
        cur = q1.front();
        q1.pop();
        q2.push(cur);
        for (List* search = ptr[cur]->plist; search; search = search->next) {
            if (!visit[search->data]) {
                q1.push(search->data);
                visit[search->data] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    while (!q2.empty()) {
        cur = q2.front();
        q2.pop();
        List* search = ptr[cur]->plist;
        for (; search; search = search->next) {
            if (!visit[search->data]) {
                break;
            }
        }
        if (search) {
            q2.push(cur);
        }
        else {
            for (search = ptr[cur]->plist; search; search = search->next) {
                ptr[cur]->parent |= ptr[search->data]->parent;
            }
            visit[cur] = true;
        }
    }

    delete[] visit;
}

int count(Element**& ptr, int n) {
    Result r1 = ptr[n]->parent, r2 = ptr[n]->child;
    unsigned long long temp = 1ull;
    int count = 0;
    for (int i = 0; i < 64; i++, temp <<= 1) {
        if (r1.result[0] & temp || r2.result[0] & temp) {
            count++;
        }
    }
    temp = 1ull;
    for (int i = 0; i < 37; i++, temp <<= 1) {
        if (r1.result[1] & temp || r2.result[1] & temp) {
            count++;
        }
    }

    return count;
}