/*
N의 배수 번호 양 세기
- 첫 번째: N, 두 번째: 2N, ..., k 번째 kN

Q. 셌던 번호들의 각 자리수에서 0~9 모든 숫자 보는 것은 양을 몇 번 센 시점?
--> k 구하는 것 X / kN 구하는 것 O !!!
*/

#include <iostream>

using namespace std;

int main(void) {
    int test_case, n;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        cin >> n;

        int k = 1, kth_n = 0, r = 0;
        unsigned int flag = 0b0000000000; // bit flag
        unsigned int check = 0b1111111111;

        while (flag != check) {
            kth_n = k * n; // kth

            for (int i=kth_n; i>0; i/=10) {
                r = i % 10; // units
                flag |= 1 << r; // flag on
            }

            k++; // update k
        }

        cout << "#" << t << " " << kth_n << endl;
    }
}