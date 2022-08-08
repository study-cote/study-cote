int adjList[100][5] = {0,};
int childNum[100] = {0};
bool visited[100] = {false};
int ans = -1;
bool flag = false;

void dfs_init(int N, int path[100][2])
{
    // init childNum[]
    for (int i=0; i<100; i++) {
        childNum[i] = 0;
        
        for (int j=0; j<5; j++) {
            adjList[i][j] = 0;
        }
    }
    
    // save input as adjacency list
    for (int i=0; i<N; i++) {
        int king = path[i][0];
        int nchild = childNum[king];

        if (nchild > 5)
            return;

        adjList[king][nchild] = path[i][1];
        childNum[king] = nchild+1;
    }

}

void dfs_node(int n, int origin) {
    visited[n] = true;

    for (int i=0; i<childNum[n]; i++) {
        int next = adjList[n][i];
        
        if (next>origin && !flag) { // change only at first time -> flag
            ans = next;
            flag = true;
        }
        
        if (!visited[next])
            dfs_node(next, origin);
    }
}

int dfs(int n)
{
    // init
    for (int i=0; i<100; i++)
        visited[i] = false;
    ans = -1;
    flag = false;
    
    // start dfs
    dfs_node(n, n);
    
    return ans;
}
