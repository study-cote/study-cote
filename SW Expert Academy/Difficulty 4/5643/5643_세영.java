import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
 
public class D4_5643 {
 
    static int N, M, arr[][];
    static int[] big, small;
 
    public static void main(String[] args) throws IOException {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
 
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
 
            N = Integer.parseInt(br.readLine());
            M = Integer.parseInt(br.readLine());
 
            arr = new int[N + 1][N + 1];
            big = new int[N + 1];
            small = new int[N + 1];
            
            int i, j;
            for (int m = 1; m <= M; m++) {
                st = new StringTokenizer(br.readLine());
                
                i = Integer.parseInt(st.nextToken());
                j = Integer.parseInt(st.nextToken());
                
                arr[i][j] = 1;
            }
 
            int res = 0;
            for (int n = 1; n <= N; n++) {
                dfs(n, n, new boolean[N + 1]);
            }
            
            for (int n = 1; n <= N; n++) {
                if(big[n] + small[n] == N - 1) res++;
            }
            
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
 
    }
    
    static void dfs(int n, int cur, boolean[] visited) { 
 
        visited[cur] = true;
        
        for (int i = 1; i <= N; i++) {
            if(arr[cur][i] == 1 && !visited[i]) {
                big[n]++;
                small[i]++;
                dfs(n, i, visited);
            }
        }
    }
    
}