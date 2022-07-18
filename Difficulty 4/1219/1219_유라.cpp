#include <iostream>

using namespace std;

int vertex1[100] = {-1};
int vertex2[100] = {-1};
int ans = 0;

// inorder traverse
// does not consider the cycle
void traverse(int v) {
    if (vertex1[v] == -1 && vertex2[v] == -1){
        if (v == 99)
            ans = 1;
        return;
    }
        
    if (vertex1[v] != -1)
        traverse(vertex1[v]);

    if (vertex2[v] != -1)
        traverse(vertex2[v]);
}

int main(void) {
    int test_case, roadnum, v1, v2;

    for (int i=1; i<=10; i++) {
        scanf("%d %d", &test_case, &roadnum);
        
        // init
        fill_n(vertex1, 100, -1);
        fill_n(vertex2, 100, -1);
        ans = 0;

        for (int j=0; j<roadnum; j++) {
            scanf("%d %d", &v1, &v2);

            if (vertex1[v1] == -1)
                vertex1[v1] = v2;
            else {
                vertex2[v1] = v2;
            }
        }

        traverse(0);

        printf("#%d %d\n", i, ans);
    }

    return 0;
}