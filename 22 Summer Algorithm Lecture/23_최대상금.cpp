#include <iostream>
#include <algorithm>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}

using namespace std;

// 그리디 알고리즘 + 예외처리
string maxPrize(string num, int ex) {
    string maxNum = num; // 주어진 숫자에서 나올 수 있는 최대치 저장
    sort(maxNum.begin(), maxNum.end(), greater<char>());

    int exCnt = 0, idx = 0, prev = 0, prevMax = 0;
    char tmp;
    bool changeFlag = false, sameNum = false;

    while (exCnt < ex && idx < num.size()-1) {
        int maxIdx = num.size()-1;

        for (int i=idx+1; i<num.size()-1; i++) {
            if (num[i] > num[maxIdx]) // 가장 큰 숫자 찾기
                maxIdx = i;

            else if (num[i] == num[maxIdx]) {
                sameNum = true; // 숫자 중복 체크

                if (maxIdx < i) // 같은 숫자일 경우 더 큰 인덱스 저장
                    maxIdx = i;
            }
        }

        // 현재 숫자가 뒤의 나머지 숫자들보다 클 경우 -> 변경 필요 X
        if (num[maxIdx] < num[idx]) {
            idx++; // 다음 숫자 체크 위해 인덱스 증가
            continue;
        }

        else {
            SWAP(num[idx], num[maxIdx], tmp);
        
            // 이전 반복에서 교환한 숫자와 현재 교환한 숫자가 동일할 경우,
            // -> 교환된 두 숫자들 (뒤로 밀린 숫자) 끼리 정렬
            // 테스트 케이스 32888 -> 답: 88832 / 오답: 88823
            if (prev == num[idx] && num[prevMax] > num[maxIdx])
                SWAP(num[prevMax], num[maxIdx], tmp);

            // 다음 반복에서 위의 조건문 만족 여부 체크하기 위해 현재 교환 인덱스 저장
            prev = num[idx];
            prevMax = maxIdx;

            // 인덱스, 교환횟수 업데이트
            idx++;
            exCnt++;

            // 최대치에 도달했을 경우, 체크하고 반복문 해제
            // 처음에 검사하지 않는 이유 -> 동일 숫자 있는지 체크해야 함 (for문 돌아야 함)
            if (num == maxNum) {
                changeFlag = true;
                break;
            }
        }
    }

    // 만약 주어진 숫자를 최대치로 변경할 수 있는 경우
    if (changeFlag) {
        // 최대치로 변경했는데, 아직 변경 횟수가 남은 경우
        while (exCnt < ex) {
            // 숫자가 중복되는 경우, 해당 숫자들만 계속 바꿔서 최대치 유지
            // 중복되지 않는 경우, 변화 최소화하기 위해 끝의 두자리만 계속 변경
            if (!sameNum) {
                SWAP(num[num.size()-1], num[num.size()-2], tmp);
            }
            exCnt++;
        }
    }

    // 테스트케이스 14 / 15 에서 통과하지 못했던 케이스 -> 4321 2 (답: 4321, 나: 4312) 
    // 만약 현재가 주어진 교환횟수 내에서 최대치로 바꿀 수 있는 숫자인 경우 OR 처음 주어진 숫자가 최선인 경우
    // -> 변화 최소화하기 위해 남은 변화 횟수동안 끝의 두자리만 계속 변경
    else if (exCnt < ex) {
        while (exCnt < ex) {
            SWAP(num[num.size()-1], num[num.size()-2], tmp);
            exCnt++;
        }
    }

    return num;
}

int main(void) {
    int testCase, exchange;
    string num;
    cin >> testCase;

    for (int t=1; t<=testCase; t++) {
        cin >> num >> exchange;
        num = maxPrize(num, exchange);
        cout << "#" << t << " " << num << endl;
    }

    return 0;
}