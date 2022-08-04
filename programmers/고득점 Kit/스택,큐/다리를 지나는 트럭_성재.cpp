#include <string>
#include <vector>

using namespace std;

struct List {
    int remain_length;
    int weight;
    List* next;

    List(int, int);
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    List* front = NULL, * rear = NULL;
    for (int cur = 0; cur < truck_weights.size();) {
        answer++;
        if (front && front->remain_length == 1) {
            weight += front->weight;
            List* temp = front;
            front = front->next;
            delete temp;
        }
        for (List* ptr = front; ptr; ptr = ptr->next) {
            ptr->remain_length--;
        }
        if (truck_weights[cur] <= weight) {
            List* temp = new List(bridge_length, truck_weights[cur]);
            if (front) {
                rear->next = temp;
            }
            else {
                front = temp;
            }
            rear = temp;
            weight -= truck_weights[cur++];
        }
    }
    while (front) {
        answer++;
        if (front && front->remain_length == 1) {
            List* temp = front;
            front = front->next;
            delete temp;
        }
        for (List* ptr = front; ptr; ptr = ptr->next) {
            ptr->remain_length--;
        }
    }

    return answer;
}

List::List(int len, int w) : remain_length(len), weight(w), next(NULL) {

}