#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = brown / 2 - 3, j = 1; i >= j; i--, j++) {
        if (i * j == yellow) {
            answer.push_back(i + 2);
            answer.push_back(j + 2);
        }
    }

    return answer;
}