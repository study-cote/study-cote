#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    string data;
    int length;

    Element(string, int);
    bool operator<(const Element& e) const;
};

struct List {
    string data;
    List* next;

    List(string, List*);
    ~List();
};

bool solution(vector<string> phone_book) {
    bool answer = true;

    int bucketSize = 10000;
    List** hash = new List * [bucketSize];
    for (int i = 0; i < bucketSize; i++) {
        hash[i] = NULL;
    }
    priority_queue<Element> PQ;
    for (int i = 0; i < phone_book.size(); i++) {
        Element temp(phone_book[i], phone_book[i].length());
        PQ.push(temp);
    }

    for (int i = 0; answer && !PQ.empty(); i++) {
        int bucket = 0;
        string str = PQ.top().data;
        PQ.pop();
        for (int j = 1; j <= str.length(); j++) {
            bucket = 0;
            string temp = str.substr(0, j);
            for (int k = 1; k <= temp.length(); k++) {
                bucket += (k * k * temp[k - 1]);
            }
            bucket %= bucketSize;
            for (List* search = hash[bucket]; search; search = search->next) {
                if (search->data.compare(temp) == 0) {
                    answer = false;
                }
            }
        }
        hash[bucket] = new List(str, hash[bucket]);
    }

    for (int i = 0; i < bucketSize; i++) {
        if (hash[i]) {
            delete hash[i];
        }
    }

    return answer;
}

Element::Element(string str, int len) : data(str), length(len) {

}

bool Element::operator<(const Element& e) const {
    return this->length > e.length;
}

List::List(string str, List* ptr) : data(str), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}