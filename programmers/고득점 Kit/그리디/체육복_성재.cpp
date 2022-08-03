#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> lost_copy, reserve_copy;

    vector<int>::iterator i = lost.begin(), j = reserve.begin();
    while (i != lost.end() && j != reserve.end()) {
        if (*i == *j) {
            i++;
            j++;
        }
        else if (*i < *j) {
            lost_copy.push_back(*i);
            i++;
        }
        else {
            reserve_copy.push_back(*j);
            j++;
        }
    }
    for (; i != lost.end(); i++) {
        lost_copy.push_back(*i);
    }
    for (; j != reserve.end(); j++) {
        reserve_copy.push_back(*j);
    }

    answer = n - lost_copy.size();

    for (i = lost_copy.begin(), j = reserve_copy.begin(); i != lost_copy.end() && j != reserve_copy.end();) {
        if (*i < *j) {
            if (*i == (*j) - 1) {
                answer++;
                j++;
            }
            i++;
        }
        else {
            if (*i == (*j) + 1) {
                answer++;
                i++;
            }
            j++;
        }
    }

    return answer;
}