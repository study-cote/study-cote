#include <iostream>
#include <queue>

using namespace std;

int map[16][16] = {1};
int trail[16][16] = {0};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int row, int col) {
    queue <pair<int, int>> q;
    
    trail[row][col] = 1; // check visit
    q.push({row, col});

    while(!q.empty()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        q.pop();

        for (int i=0; i<4; i++) {
            int next_row = cur_row + dir[i][0];
            int next_col = cur_col + dir[i][1];

            if (map[next_row][next_col] == 3)
                return 1;

            if (next_row >= 0 && next_row < 16
                && next_col >= 0 && next_col < 16
                && !map[next_row][next_col] && !trail[next_row][next_col]) {
                q.push({next_row, next_col});
                trail[next_row][next_col] = 1;
            }
        }
    }

    return 0;
}


int main(void) {
    int test_case, start_row, start_col;

    for (int t=1; t<=10; t++) {
        cin >> test_case;
        
        for (int i=0; i<16; i++) {
            for (int j=0; j<16; j++) {
                scanf("%1d", &map[i][j]);
                trail[i][j] = 0;

                if (map[i][j] == 2) { // start point
                    start_row = i;
                    start_col = j;
                }
            }
        }

        cout << "#" << t << " " << bfs(start_row, start_col) << endl;

    }

    return 0;
}