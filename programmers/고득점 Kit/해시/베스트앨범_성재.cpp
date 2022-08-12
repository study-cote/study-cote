#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    string genre;
    int index[2], play[2];
    int sum;

    Element(string, int, int);
    bool operator<(const Element&) const;
};

struct List {
    Element data;
    List* next;

    List(string, int, int, List*);
    ~List();
};

class Hash {
    const int size = 100;
    List** list;

public:
    Hash();
    ~Hash();

    void addData(string, int, int);
    void setQ(priority_queue<Element>&);
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    Hash hash;
    for (int i = 0; i < genres.size(); i++) {
        hash.addData(genres[i], i, plays[i]);
    }

    priority_queue<Element> PQ;
    hash.setQ(PQ);

    while (!PQ.empty()) {
        Element temp = PQ.top();
        PQ.pop();
        answer.push_back(temp.index[0]);
        if (temp.index[1] >= 0) {
            answer.push_back(temp.index[1]);
        }
    }

    return answer;
}

Element::Element(string s, int i, int p) : genre(s), sum(p) {
    index[0] = i;
    play[0] = p;
    index[1] = -1;
}

bool Element::operator<(const Element& e) const {
    return this->sum < e.sum;
}

List::List(string s, int i, int p, List* ptr) : data(s, i, p), next(ptr) {

}

List::~List() {
    if (next) {
        delete next;
    }
}

Hash::Hash() {
    list = new List * [size];
    for (int i = 0; i < size; i++) {
        list[i] = NULL;
    }
}

Hash::~Hash() {
    for (int i = 0; i < size; i++) {
        if (list[i]) {
            delete list[i];
        }
    }
    delete[] list;
}

void Hash::addData(string genre, int i, int play) {
    int bucket = 0;
    for (int i = 0; i < genre.length(); i++) {
        bucket += ((i + 1) * (i + 1) * genre[i]);
    }
    bucket %= size;

    List* search = list[bucket];
    for (; search; search = search->next) {
        if (search->data.genre.compare(genre) == 0) {
            search->data.sum += play;
            if (search->data.index[1] < 0) {
                if (search->data.play[0] < play) {
                    search->data.index[1] = search->data.index[0];
                    search->data.play[1] = search->data.play[0];
                    search->data.index[0] = i;
                    search->data.play[0] = play;
                }
                else {
                    search->data.index[1] = i;
                    search->data.play[1] = play;
                }
            }
            else {
                if (search->data.play[0] < play) {
                    search->data.index[1] = search->data.index[0];
                    search->data.play[1] = search->data.play[0];
                    search->data.index[0] = i;
                    search->data.play[0] = play;
                }
                else if (search->data.play[1] < play) {
                    search->data.index[1] = i;
                    search->data.play[1] = play;
                }
            }
            break;
        }
    }
    if (!search) {
        list[bucket] = new List(genre, i, play, list[bucket]);
    }
}

void Hash::setQ(priority_queue<Element>& PQ) {
    for (int i = 0; i < size; i++) {
        for (List* search = list[i]; search; search = search->next) {
            PQ.push(search->data);
        }
    }
}