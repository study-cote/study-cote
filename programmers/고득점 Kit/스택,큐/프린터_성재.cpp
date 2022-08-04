#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int count[10];
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < priorities.size(); i++) {
        count[priorities[i]]++;
    }
    int cur = 9;
    for (; cur >= 0; cur--) {
        if (count[cur]) {
            break;
        }
    }
    int i = 0;
    while (true) {
        if (priorities[i] == cur) {
            answer++;
            if (i == location) {
                break;
            }
            count[cur]--;
            while (!count[cur]) {
                cur--;
            }
        }

        i = (i + 1) % priorities.size();
    }

    return answer;
}