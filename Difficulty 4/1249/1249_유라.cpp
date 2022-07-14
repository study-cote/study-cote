#include <iostream>
#include <queue>

using namespace std;

int map[101][101] = {0}; //map
int dist[101][101] = {999999}; // distance
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // direction
int n; // map size

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    
    dist[row][col] = 0;
    q.push({row, col});

    while(!q.empty()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) { // traverse four direction
            int next_row = cur_row + dir[i][0];
            int next_col = cur_col + dir[i][1];

            if(next_row >= 0 && next_row < n
                && next_col >= 0 && next_col < n
                && dist[next_row][next_col] > dist[cur_row][cur_col] + map[next_row][next_col]) {
                q.push({next_row, next_col});
                dist[next_row][next_col] = dist[cur_row][cur_col] + map[next_row][next_col];
            }
        }
    }

    return;
}

int main(void) {
    int test_case;
    cin >> test_case;

    // input array
    for(int T=1; T<=test_case; T++) {
        cin >> n;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%1d", &map[i][j]);
                dist[i][j] = 999999;
            }
        }

        bfs(0, 0);

        cout << "#" << T << " " << dist[n-1][n-1] << endl;
    }

    return 0;
}