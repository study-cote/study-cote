#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.emplace_back(arr[0]);
    for (int i=1; i<arr.size(); i++) {
        if (arr[i] != answer.back())
            answer.emplace_back(arr[i]);
    }

    return answer;
}