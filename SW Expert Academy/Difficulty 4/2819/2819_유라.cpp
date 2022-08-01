#include <iostream>
#include <set>
#include <string>

using namespace std;

char map[4][4] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
set<string> s;

void dfs(int row, int col, int cnt, string num) {
    if (cnt == 7) {
        s.insert(num);
        return;
    }

    for (int i=0; i<4; i++) {
        int next_row = row + dir[i][0];
        int next_col = col + dir[i][1];

        if (next_row >= 0 && next_row < 4 && next_col >= 0 && next_col < 4) {
            dfs(next_row, next_col, cnt + 1, num + map[next_row][next_col]);
        }
    }
}

int main(void) {
    int test_case;
    scanf("%d", &test_case);
    
    for (int t=1; t<=test_case; t++) {
        s.clear(); // init set

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                dfs(i, j, 0, "");
            }
        }

        printf("#%d %d\n", t, (int)(s.size()));
    }

    return 0;
}