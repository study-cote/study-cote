#include <string>
#include <vector>

using namespace std;

void func(vector<vector<int>>, unsigned int, int, int, int&);

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    unsigned int visit = (1u << dungeons.size()) - 1;
    func(dungeons, visit, k, 0, answer);

    return answer;
}

void func(vector<vector<int>> arr, unsigned int visit, int k, int count, int& answer) {
    if (!visit) {
        if (count > answer) {
            answer = count;
        }
        return;
    }

    bool valid = false;
    int i = 0;
    for (unsigned int temp = 1u; temp <= visit; temp <<= 1, i++) {
        if (temp & visit) {
            if (arr[i][0] <= k) {
                valid = true;
                func(arr, visit ^ temp, k - arr[i][1], count + 1, answer);
            }
        }
    }
    if (!valid) {
        if (count > answer) {
            answer = count;
        }
    }
}