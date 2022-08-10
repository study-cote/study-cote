#include <iostream>
#include <string>
#include <vector>

using namespace std;

// // 시간 초과 - 테스트 케이스 10 /20
// int findWord(string b, string w) {
//     int cnt = 0; // count found word
//     int idx = 0; // word size
//     string tmp;
//     for (int i=0; i<=b.size()-w.size(); i++) {
//         while (b[i+idx] == w[idx] && idx<w.size()) {
//             tmp += b[i+idx];
//             idx++; 
//         }
//         // find word
//         if (tmp.size() == w.size() && tmp == w)
//             cnt++;
// 		// init
//         idx = 0;
//         tmp = "";
//     }
//     return cnt;
// }

// generate partial match vector
vector <int> partialMatch(string w) {
    vector <int> pi(w.size(), 0);
    int begin = 1, matched = 0;

    while (begin+matched < w.size()) {
        if (w[begin+matched] == w[matched]) {
            ++matched;
            // 앞에서 matched 먼저 증가시켜주었기 때문에 -1 해줘야 지금 검사한 위치 값 업데이트 가능
            pi[begin+matched-1] = matched;
        }

        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return pi;
}

// KMP 알고리즘 사용해야 시간 초과 해결 가능할듯
int kmp(string b, string w) {
    int wordCnt = 0;
    int begin = 0, matched = 0;
    vector <int> pi = partialMatch(w);

    while (begin <= b.size() - w.size()) {
        if (matched < w.size() && b[begin+matched] == w[matched]) {
            ++matched;
            if (matched == w.size())
                wordCnt++;
        }

        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return wordCnt;
}

int main(void) {
    int testCase;
    scanf("%d", &testCase);

    for (int t=1; t<=testCase; t++) {
        string book, word;
        cin >> book >> word;
        
        printf("#%d %d\n", t, kmp(book, word));
    }

    return 0;
}