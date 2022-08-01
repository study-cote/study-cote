#include <map>

using namespace std;

map <int, int> score;
map <int, int> team;

// 테스트 케이스 시작 시 고용된 병사 없음
void init()
{
    score.clear();
    team.clear();
}

// 고유번호 mID, 소속팀 mTeam, 평판 점수 mScore
// 한 테스트 케이스 내에서 동일 mID 가진 병사의 중복 고용은 없음
void hire(int mID, int mTeam, int mScore)
{
    score.insert({mID, mScore});
    team.insert({mID, mTeam});
}

// 고유번호 mID인 병사 해고
// 함수 호출시, 고유번호 mID인 병사 고용 보장
void fire(int mID)
{
    score.erase(mID);
    team.erase(mID);
}

// 고유번호 mID인 병사의 평판 점수를 mScore로 변경
// 고유번호 mID인 병사 고용 보장
void updateSoldier(int mID, int mScore)
{
    score[mID] = mScore;
}

// 소속팀 mTeam인 병사들의 평판 점수 모두 변경
// 소속팀 mTeam인 병사가 한 명 이상 고용되어 있음 보장
void updateTeam(int mTeam, int mChangeScore)
{
    for (auto iter = team.begin(); iter != team.end(); iter++) {
        if (iter->second == mTeam) {
            int updateScore = score[iter->first] + mChangeScore;

            // change score according to updateScore
            if (updateScore > 5)
                score[iter->first] = 5;
            else if (updateScore < 1)
                score[iter->first] = 1;
            else
                score[iter->first] = updateScore;
        }
    }
}

// 소속팀이 mTeam인 병사들 중 가장 평판 점수 높은 병사 고유번호 반환
// 여러 명일 경우, 고유번호가 가장 큰 병사의 고유번호 반환
// 소속팀 mTeam인 병사가 한 명 이상 고용되어 있음 보장
int bestSoldier(int mTeam)
{
    int maxScore = 0, maxID = 0;

    for (auto iter = team.begin(); iter != team.end(); iter++) {
        if (iter->second == mTeam) {
            if (score[iter->first] > maxScore) {
                maxScore = score[iter->first];
                maxID = iter->first;
            }
        }
    }

    return maxID;
}