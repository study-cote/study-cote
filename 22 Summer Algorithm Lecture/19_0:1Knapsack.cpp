#include <iostream>
#include <vector>

using namespace std;

vector <int> volume, cost;
int k; // knapsack size
int n; // number of things
//int maxCost;
int dp[101][1001] = {0,};

/* BACKTRACKING ver. -> have to fix */
// bool promising(int curIdx, int curCost, int curVolume);
// void knapsack_bt(int curIdx, int curCost, int curVol);

void knapsack() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (volume[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(cost[i-1] + dp[i-1][j-volume[i-1]], dp[i-1][j]);
            }
        }
    }
}

int main(void) {
    int testCase, v, c;
    cin >> testCase;

    for (int t=1; t<=testCase; t++) {
        // init
        volume.clear();
        cost.clear();
        //maxCost = 0;
        
        // get input
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> v >> c;
            volume.emplace_back(v);
            cost.emplace_back(c);
        }

       // knapsack_bt(-1, 0, 0);
       knapsack();

        // print maximum cost
        cout << "#" << t << " " << dp[n][k] << endl;
    }

    return 0;
}

// bool promising(int curIdx, int curCost, int curVolume) {
//     int totalVol;
//     int expectCost;
//     int i;

//     if (curVolume >= k)
//         return false;

//     else {
//         expectCost = curCost;
//         totalVol = curVolume;

//         for (i=curIdx+1; i<n; i++) {
//             if (totalVol + volume[i] > k)
//                 break;
//             expectCost += cost[i];
//             totalVol += volume[i];
//         }

//         if (i<n)
//             expectCost = expectCost + (k-totalVol) * (cost[i]/volume[i]);
        
//         return expectCost > maxCost;
//     }
// }

// void knapsack_bt(int curIdx, int curCost, int curVol) {
//     if (curCost > maxCost && curVol <= k)
//         maxCost = curCost;

//     if (promising(curIdx, curCost, curVol)) {
//             // packing current one
//             knapsack_bt(curIdx+1, curCost + cost[curIdx+1], curVol + volume[curIdx+1]);
//             // skip to next one
//             knapsack_bt(curIdx+1, curCost, curVol);
//     }
// }