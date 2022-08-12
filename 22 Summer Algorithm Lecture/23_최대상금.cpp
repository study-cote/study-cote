#include <iostream>
#include <algorithm>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}

using namespace std;

string maxPrize(string num, int ex) {
    string maxNum = num;
    sort(maxNum.begin(), maxNum.end(), greater<char>());

    //ex = ex > num.size() ? num.size() : ex;
  
    int exCnt = 0, idx = 0, prev = 0, prevMax = 0;
    char tmp;
    bool changeFlag = false, sameNum = false;
    while (exCnt < ex && idx < num.size()-1) {
        int maxIdx = num.size()-1;

        for (int i=idx+1; i<num.size()-1; i++) {
            if (num[i] > num[maxIdx])
                maxIdx = i;
            else if (num[i] == num[maxIdx]) {
                sameNum = true;
                if (maxIdx < i)
                    maxIdx = i;
            }
        }

        //cout << idx << " " << maxIdx << endl;

        if (num[maxIdx] < num[idx]) {
            idx++;
            continue;
        }
        else {
            SWAP(num[idx], num[maxIdx], tmp);
        
            if (prev == num[idx] && num[prevMax] > num[maxIdx])
                SWAP(num[prevMax], num[maxIdx], tmp);

            //cout << num << endl;
            prev = num[idx];
            prevMax = maxIdx;

            idx++;
            exCnt++;

            if (num == maxNum) {
                changeFlag = true;
                break;
            }
        }
    }

    //cout << exCnt << " " << num << " " << maxNum << endl;

    if (changeFlag) {
        while (exCnt < ex) {
            if (!sameNum && ex/2 != 0) {
                SWAP(num[num.size()-1], num[num.size()-2], tmp);
            }
            exCnt++;
        }
    }
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
        //cout << num << " " << exchange << endl;
        num = maxPrize(num, exchange);
        cout << "#" << t << " " << num << endl;
    }

    return 0;
}

/*
#1 321
#2 7732
#3 857174 / 857147
#4 87664
#5 88832
#6 777770
#7 966345 / 966354
#8 954311
#9 332211
#10 987645
*/