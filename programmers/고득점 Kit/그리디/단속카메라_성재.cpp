#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    int start, end;

    bool operator<(const Element&) const;
};

int solution(vector<vector<int>> routes) {
    int answer = 0;

    priority_queue<Element> PQ;
    for (int i = 0; i < routes.size(); i++) {
        Element temp = { routes[i][0], routes[i][1] };
        PQ.push(temp);
    }
    int min = PQ.top().end;
    PQ.pop();
    while (!PQ.empty()) {
        if (PQ.top().start > min) {
            answer++;
            min = PQ.top().end;
        }
        else {
            if (PQ.top().end < min) {
                min = PQ.top().end;
            }
        }
        PQ.pop();
    }
    answer++;

    return answer;
}

bool Element::operator<(const Element& e) const {
    if (this->start == e.start) {
        return this->end > e.end;
    }
    else {
        return this->start > e.start;
    }
}