#include <iostream>

using namespace std;

int kind[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

void cashBack(int money) {
    for (int idx=0; idx<8; money>=0) {
    	cout << money/kind[idx] << " ";
        money %= kind[idx++];
    }
    cout << endl;
}

int main(void) {
    int testCase, n;
    cin >> testCase;

    for (int t=1; t<=testCase; t++) {
        cin >> n;
        // print answer
        cout << "#" << t << endl;
        cashBack(n);
    }

    return 0;
}