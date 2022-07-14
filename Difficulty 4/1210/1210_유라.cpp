#include <iostream>
#define length 100

using namespace std;

int map[100][100];
int trail[100][100];
int up[1][2] = {{-1, 0}}; // up
int dir[2] = {-1, 1}; // left, right

int traverse(int col) {
    int row = length-1;
    trail[row][col] = 1;

    while(row > 0) {

        if (col-1 >= 0 && map[row][col-1] && !trail[row][col-1]) { // left
            col -= 1;
        }
        else if (col+1 < length && map[row][col+1] && !trail[row][col+1]) { // right
            col += 1;
        }
        else {
            row -= 1;
        }

        trail[row][col] = 1;
    }

    return col;
}

int main(void) {
    int test_case;

    for (int t=0; t<10; t++) {
        cin >> test_case;

        // input array
        for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                scanf("%1d", &map[i][j]);
                trail[i][j] = 0; // init
            }
        }

        // find finish point
        int finish_col;
        for (int i=0; i<length; i++) {
            if (map[length-1][i] == 2) {
                finish_col = i;
                break;
            }
        }

        // get answer
        cout << "#" << test_case << " " << traverse(finish_col) << endl;
    }

    return 0;
}
