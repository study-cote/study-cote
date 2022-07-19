/*
정수 N, M 주어질 때, M의 이진수 표현에서 마지막 N 비트가 1인지 판별
1이면 ON / 아니면 OFF 출력
*/

#include <iostream>
//#include <bitset>

using namespace std;

int main(void) {
    int test_case, n;
    unsigned int m;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        unsigned int check = 0; // init !!
        
        cin >> n >> m;

        for (int i=0; i<n; i++) {
            check |= (1 << i); // N to bits
        }

        cout << '#' << t << " " << (((check & m) == check) ? "ON" : "OFF") << endl;
    }

    return 0;
}
