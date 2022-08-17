#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i=0; i<participant.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}

    /* 기존 코드 (효율성 0점)
    for (int i=0; i<participant.size(); i++) {
        auto it = find(completion.begin(), completion.end(), participant[i]); // 완주 멤버에 있는지 확인
        if(it == completion.end()) { // 없으면 해당 멤버 반환
            answer = participant[i];
            break;
        }
        else { // 있으면 완주 멤버에서 해당 멤버 삭제 (중복 확인 피하기 위해)
            completion.erase(it);
        }
    }
    */