#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> days;
    for (vector<int>::iterator i = progresses.begin(), j = speeds.begin(); i != progresses.end(), j != speeds.end(); i++, j++) {
        days.push(ceil((double)(100 - *i) / (*j)));
    }
    int cur = days.front(), count = 1;
    days.pop();
    while (!days.empty()) {
        if (days.front() > cur) {
            answer.push_back(count);
            cur = days.front();
            count = 0;
        }
        count++;
        days.pop();
    }
    answer.push_back(count);

    return answer;
}