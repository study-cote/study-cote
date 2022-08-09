#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

/* 아래 함수 (brute force) 는 시간 초과 */
// int cmpString(vector <string> one, vector <string> two) {
//     int cnt = 0;
//     for (int i=0; i<one.size(); i++) {
//         for (int j=0; j<two.size(); j++) {
//             if (one[i].size() != two[j].size())
//                 continue;
//             if (one[i] == two[j])
//                 cnt++;
//         }
//     }
//     return cnt;
// }

int main(void) {
    int testCase, n, m;
    int cnt = 0;
    string tmp;

    // set 사용했을 때 아래와 동일한 코드에서 시간 초과 걸림. unordered_set은 정렬 X라 시간 내에 실행된 듯
    unordered_set <string> str;

    scanf("%d", &testCase);

    for (int t=1; t<=testCase; t++) {
        scanf("%d %d", &n, &m);

        // init
        str.clear();
        cnt = 0;

        for (int i=0; i<n; i++) {
            cin >> tmp;
            str.insert(tmp);
        }

        for (int i=0; i<m; i++) {
            cin >> tmp;
            if (str.find(tmp) != str.end()) // find intersection
                cnt++;
        }

        printf("#%d %d\n", t, cnt);
    }

    return 0;
}