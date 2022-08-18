#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map <int, int> release;
    int prevDay = 1;
    
    for (int i=0; i<progresses.size(); i++) {
        // 작업 완료까지 남은 날짜 계산
        int leftDay = (100 - progresses[i]) / speeds[i];
        
        // **11번 테스트 케이스 : (진도/속도)의 나머지가 있을 때 (ex. 2.5일 남음)
        if ((100 - progresses[i]) % speeds[i] > 0)
            leftDay += 1;
        
        // 이전 작업보다 빠르게 끝날 경우, 이전 작업 완료까지 기다려야 함
        if (leftDay < prevDay) {
            leftDay = prevDay;
        }
        
        prevDay = leftDay;

        // 각 날짜별 배포되는 작업의 수 저장
        if (release.find(leftDay) != release.end())
            release[leftDay] += 1;
        else release[leftDay] = 1;
    }
    
    // map to vector
    for (auto it : release) {
        answer.emplace_back(it.second);
    }    
    
    return answer;
}