#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set <int> numSet(nums.begin(), nums.end()); // 중복 제거
    
    // 전체 종류의 수 > 가질 수 있는 종류의 수 -> 가질 수 있는 종류의 수
    if ((nums.size()/2) < numSet.size()) {
        answer = nums.size()/2;
    }
    // 전체 종류의 수 <= 가질 수 있는 종류의 수 -> 전체 종류의 수
    else {
        answer = numSet.size();
    }
    
    return answer;
}