class Solution {
    static int res;
    
    public int solution(int k, int[][] dungeons) {
        boolean visited[] = new boolean[dungeons.length];
        int answer = -1;
        
        answer = dfs(k, dungeons, 0, visited);
        return answer;
    }
    
    public int dfs(int k, int[][] arr, int cnt, boolean[] visited) {
        res = Math.max(cnt, res);
    	for (int i = 0; i < arr.length; i++) {
            if (visited[i] || arr[i][0] > k) continue;
            
            visited[i] = true;
            dfs(k-arr[i][1], arr, cnt+1, visited);
            visited[i] = false;
        }
        
        return res;
    }
}