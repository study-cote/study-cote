#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    int data;

    bool operator<(const Element& e) const;
};

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<Element> PQ;
    Element temp;
    for (int i = 0; i < scoville.size(); i++) {
        temp.data = scoville[i];
        PQ.push(temp);
    }
    while (PQ.size() > 1 && PQ.top().data < K) {
        Element a = PQ.top();
        PQ.pop();
        Element b = PQ.top();
        PQ.pop();

        temp.data = a.data + 2 * b.data;
        PQ.push(temp);
        answer++;
    }
    if (PQ.top().data < K) {
        answer = -1;
    }

    return answer;
}

bool Element::operator<(const Element& e) const {
    return this->data > e.data;
}