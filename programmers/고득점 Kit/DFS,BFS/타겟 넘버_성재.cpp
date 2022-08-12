#include <string>
#include <vector>

using namespace std;

void func(vector<int>, int, int, int, int&);

int solution(vector<int> numbers, int target) {
    int answer = 0;

    func(numbers, 0, 0, target, answer);

    return answer;
}

void func(vector<int> n, int cur, int sum, int target, int& answer) {
    if (cur == n.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }

    func(n, cur + 1, sum + n[cur], target, answer);
    func(n, cur + 1, sum - n[cur], target, answer);
}