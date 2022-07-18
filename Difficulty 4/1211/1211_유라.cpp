#define MAX 100
#include <iostream>

using namespace std;

int map[100][100] = {0};
int trail[100][100] = {0};
int min_dist = 99999, start_col = 0;

void traverse(int col) {
    int row = 0, dist = 1, idx = col;
    trail[row][col] = 1;

    while(row < MAX-1) {
        if (col-1 >= 0 && map[row][col-1] == 1 && !trail[row][col-1])
            col -= 1;
        else if (col+1 < MAX && map[row][col+1] == 1 && !trail[row][col+1])
            col += 1;
        else 
            row += 1;

        trail[row][col] = 1;
        dist += 1; // update dist
    }

    if (dist <= min_dist) {
        min_dist = dist;
        start_col = idx;
    }

    return;
}

int main(void) {
    int test_case;

    for (int t=1; t<=10; t++) {
        scanf("%d", &test_case);

        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        min_dist = 99999;

        for (int i=0; i<100; i++) {
            if (map[0][i]) { // start point
                fill(&trail[0][0], &trail[MAX-1][MAX], 0); // init
                traverse(i);
            }
        }

        printf("#%d %d\n", test_case, start_col);
    }

    return 0;
}