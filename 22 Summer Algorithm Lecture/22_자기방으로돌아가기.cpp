#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int testCase, n, start, end;
    cin >> testCase;

    for (int t=1; t<=testCase; t++) {
        cin >> n; // 돌아가야 할 학생들의 수

        vector <pair<int, int>> rooms; // <시작 방, 도착 방>
        vector <int> corr (201, 0); // 복도

        for (int i=0; i<n; i++) {
            cin >> start >> end;
            rooms.push_back({start, end});
        }

        for (int i=0; i<rooms.size(); i++) {
            // 시작과 끝 방 중 더 큰 방번호를 끝으로, 더 작은 방번호를 시작으로 변경
            if (rooms[i].first <= rooms[i].second) {
                start = rooms[i].first;
                end = rooms[i].second;
            }
            else {
                start = rooms[i].second;
                end = rooms[i].first;
            }

            // corr 인덱스 계산 (1과 2, 3과 4가 각각 같은 복도 공유)
            start = (start%2 == 0) ? start/2 : start/2 + 1;
            end = (end%2 == 0) ? end/2 : end/2 + 1;

            // update corr
            for (int j=start; j<=end; j++)
                corr[j] += 1;
        }

        // corr 값 중 가장 큰 값 == 정답
        cout << "#" << t << " " << *max_element(corr.begin(), corr.end()) << endl;
    }
    return 0;
}