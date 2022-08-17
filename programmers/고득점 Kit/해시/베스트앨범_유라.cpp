#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair <string, int> a, pair <string, int> b) {
    return a.second > b.second; // 오름차순 정렬
}

bool cmp2(pair <int, int> a, pair <int, int> b) {
    if (a.second == b.second) { // 재생횟수 같을 경우 고유번호 낮은 것 우선
        return a.first < b.first;
    }
    return a.second > b.second; // 오름차순 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map <string, int> maxPlayGenre; // 장르당 총 재생횟수
    map <string, vector<pair <int, int>>> maxPlaySong; // 장르 별 <노래고유번호, 노래재생횟수>
    
    for (int i=0; i<genres.size(); i++) {
        if (maxPlayGenre.find(genres[i]) == maxPlayGenre.end())
            maxPlayGenre[genres[i]] = plays[i];
        else
            maxPlayGenre[genres[i]] += plays[i];
        
        maxPlaySong[genres[i]].push_back({i, plays[i]});
    }
    
    vector <pair<string, int>> vec_maxPlayGenre(maxPlayGenre.begin(), maxPlayGenre.end()); // 정렬 위해 map->vector
    sort(vec_maxPlayGenre.begin(), vec_maxPlayGenre.end(), cmp); // 장르 별 재생횟수 오름차순으로 정렬
    
    // 가장 높은 재생횟수의 장르부터 순서대로 순회
    for (int i=0; i<vec_maxPlayGenre.size(); i++) {
        auto currGenre = vec_maxPlayGenre[i].first; // 현재 장르
        
        // 현재 장르 내의 노래들 재생횟수따라 오름차순으로 정렬 (재생횟수 같을 경우 고유번호 낮은 것 우선)
        sort(maxPlaySong[currGenre].begin(), maxPlaySong[currGenre].end(), cmp2);
        
        // 현재 장르 내 최다 재생곡 답에 추가
        answer.push_back(maxPlaySong[currGenre][0].first);
        if (maxPlaySong[currGenre].size() > 1) // 1곡 이상일 경우 총 2곡 추가
            answer.push_back(maxPlaySong[currGenre][1].first);
    }
    
    return answer;
}