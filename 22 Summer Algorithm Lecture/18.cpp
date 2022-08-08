#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001] = {0, };

int LCS(string a, string b) {
    for (int i=1; i<=a.size(); i++) {
        for (int j=1; j<=b.size(); j++) {
            // same
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            // different
            else
                dp[i][j] = (dp[i-1][j] >= dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[a.size()][b.size()];
}

int main(void) {
    int test_case;
    string a, b;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        // get input
        cin >> a >> b;

        // print answer
        cout << "#" << t << " " << LCS(a, b) << endl;
    }

    return 0;
}