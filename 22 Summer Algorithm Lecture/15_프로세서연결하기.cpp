#define MAX_SIZE 12

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
vector <pair<int, int>> core; // save location of cores

int n; // map size
int maxCore; // maximum core #
int answer; // answer to print

bool checkConnect(int row, int col) {
    if (row == 0 || row == n-1 || col == 0 || col == n-1)
        return true;
    return false;
}

// check whether we can draw line in direction
bool checkDraw(int row, int col, int dir) {
    if (dir == 0) { // left
        for (int i=0; i<col; i++) {
            if (map[row][i])
                return false;
        }
    }
    else if (dir == 1) {// right
        for (int i=col+1; i<n; i++) {
            if (map[row][i])
                return false;
        }
    }
    else if (dir == 2) { // up
        for (int i=0; i<row; i++) {
            if (map[i][col])
                return false;
        }
    }
    else { // down
        for (int i=row+1; i<n; i++) {
            if (map[i][col])
                return false;
        }
    }
    return true; // can draw line
}

int drawLine(int row, int col, int dir, bool draw) {
    int dist = 0;
    
    // if draw = 1 then draw, or not remove a line
    int fill = (draw) ? 2 : 0;

    switch(dir){
        case 0: // left
            for (int i=0; i<col; i++) {
                map[row][i] = fill;
                dist++;
            }
            break;
        case 1: // right
            for (int i=col+1; i<n; i++) {
                map[row][i] = fill;
                dist++;
            }
            break;
        case 2: // up
            for (int i=0; i<row; i++) {
                map[i][col] = fill;
                dist++;
            }
            break;
        case 3: // down
            for (int i=row+1; i<n; i++) {
                map[i][col] = fill;
                dist++;
            }
            break;
        default:
            break;
    }

    return dist;
}

void dfs(int idx, int curCore, int curDist) {
    if (idx >= core.size()) { // check all cores
        if (curCore > maxCore) {
            answer = curDist; // if maximum core #, return sum of dist
            maxCore = curCore;
        }
        else if (curCore == maxCore && curDist < answer){
            answer = curDist; // if not, return minimum sum of dist
        }

        return;
    }

    else {
        for (int i=0; i<4; i++) { // check four direction
            if (checkDraw(core[idx].first, core[idx].second, i)) {
                // drawing line
                dfs(idx+1, curCore+1, curDist + drawLine(core[idx].first, core[idx].second, i, true));
                // removing line -> backtracking
                drawLine(core[idx].first, core[idx].second, i, false);
            }
        }
        // skip to next core
        dfs(idx+1, curCore, curDist);
    }
}

int main(void) {
    int test_case;
    cin >> test_case;

    for (int t=1; t<=test_case; t++) {
        // init
        maxCore = 0, answer = 987654321;
        core.clear();

        cin >> n; // map size: n x n

        // get map
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> map[i][j];
                // skip core that already connected
                if (checkConnect(i, j))
                    continue;
                // save core to vector
                if (map[i][j] == 1)
                    core.push_back({i, j});
                
            }
        }

        // curIdx, curCore, curDist
        dfs(0, 0, 0);

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}