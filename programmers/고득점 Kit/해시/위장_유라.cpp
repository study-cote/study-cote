#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int oneCount = 0, moreCount = 0;
    
    // 종류 별 개수 세기 위한 map
    map <string, int> allClothes;
    
    for (int i=0; i<clothes.size(); i++) {
        if (allClothes.find(clothes[i][1]) != allClothes.end()) {
            allClothes[clothes[i][1]] += 1;
        }
        else {
            allClothes.insert({clothes[i][1], 1});
        }
    }

    // 조합 계산
    for (auto iter=allClothes.begin(); iter!=allClothes.end(); iter++) {
        answer *= (iter->second) + 1; // 각 종류마다 입었을 때 + 안 입었을 때
    }
    
    answer -= 1; // 공집합 (전체 다 입지 않는 경우) 제외
    
    return answer;
}