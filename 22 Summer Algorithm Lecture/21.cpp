#include <iostream>
#include <vector>

using namespace std;

vector<int> kindMoney;
int kind[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

int calMoney(int money, int kind, int idx) {
    if (money/kind > 0)
        kindMoney.emplace_back(money/kind);
    else
        kindMoney.emplace_back(0);

    return money%kind;
}

void cashBack(int money) {
    int idx = 0;
    while(money >= 0 && idx < 8) {
        money = calMoney(money, kind[idx], idx);
        idx++;
    }

    for (int i=0; i<8; i++)
        cout << kindMoney[i] << " ";
}

int main(void) {
    int testCase, n;
    cin >> testCase;

    for (int t=1; t<=testCase; t++) {
        cin >> n;

        // init
        kindMoney.clear();

        // print answer
        cout << "#" << t << endl;
        cashBack(n);
        cout << endl;
    }

    return 0;
}