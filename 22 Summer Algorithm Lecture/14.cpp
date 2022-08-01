int maps[11][11] = {0};
int maps_size;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs_init(int map_size, int map[10][10]) {
    maps_size = map_size;
    for (int i=1; i<=map_size; i++) {
        for (int j=1; j<=map_size; j++)
            maps[i][j] = map[i-1][j-1];
    }
}

int bfs_node(int start_row, int start_col, int end_row, int end_col) {
    int q[100][2] = {0};
    int visited[11][11] = {0};
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int front = 0, tail = 0;
    
    q[tail][0] = start_row;
    q[tail++][1] = start_col;
    visited[start_row][start_col] = 0;
    
    while (front < tail) {
        int curr_row = q[front][0];
        int curr_col = q[front++][1];
        
        for (int i=0; i<4; i++) {
            int next_row = curr_row + dir[i][0];
            int next_col = curr_col + dir[i][1];
            
            if (next_row > 0 && next_row <= maps_size
                && next_col > 0 && next_col <= maps_size
                && !visited[next_row][next_col] && !maps[next_row][next_col]) {
                q[tail][0] = next_row;
                q[tail++][1] = next_col;
                visited[next_row][next_col] = visited[curr_row][curr_col] + 1;
            }
        }
    }
    
    int ans = visited[end_row][end_col];
    
    if (ans == 0)
        return -1;
    return ans;
}

int bfs(int x1, int y1, int x2, int y2) {
    return bfs_node(y1, x1, y2, x2);
}