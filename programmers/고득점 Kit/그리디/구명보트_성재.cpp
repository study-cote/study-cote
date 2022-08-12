#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int* remain = new int[limit + 1];
    for (int i = 40; i <= limit; i++) {
        remain[i] = 0;
    }
    for (int i = 0; i < people.size(); i++) {
        remain[people[i]]++;
    }
    int count = people.size();

    while (count) {
        int j;
        for (int i = limit; i >= 40; i--) {
            if (remain[i]) {
                remain[i]--;
                j = limit - i;
                count--;
                break;
            }
        }
        for (; j >= 40; j--) {
            if (remain[j]) {
                remain[j]--;
                count--;
                break;
            }
        }
        answer++;
    }

    delete[] remain;

    return answer;
}