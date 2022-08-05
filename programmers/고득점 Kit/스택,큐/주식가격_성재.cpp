#include <string>
#include <vector>

using namespace std;

struct List {
    int data, index, count;
    List* next;

    List(int, int, List*);
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    List* top = NULL;
    for (int i = 0; i < prices.size(); i++) {
        for (List* search = top; search; search = search->next) {
            search->count++;
        }
        for (List* ptr = top; top;) {
            if (prices[i] >= top->data) {
                break;
            }
            answer[top->index] = top->count;
            List* temp = top;
            top = top->next;
            delete temp;
        }
        top = new List(prices[i], i, top);
    }
    while (top) {
        answer[top->index] = top->count;
        List* temp = top;
        top = top->next;
        delete temp;
    }

    return answer;
}

List::List(int d, int idx, List* ptr) : data(d), index(idx), count(0), next(ptr) {

}