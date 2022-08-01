import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1861 {
	
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static int n, arr[][], start, cnt, min, max;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n][n]; min = 10000001; max = 0;
			
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					start = arr[i][j];
					cnt = 1;
					dfs(i, j);
				}
			sb.append("#").append(t).append(" ").append(min).append(" ").append(max).append("\n");	
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
	
	static void dfs(int x, int y) {
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx>=0 && nx<n && ny>=0 && ny<n) {
				if (arr[nx][ny] == arr[x][y]+1) {
					cnt++;
					dfs(nx, ny);
				}
				else {
					if (cnt > max) {
						max = cnt;
						min = start;
					}
					else if (cnt == max)
						min = Math.min(min, start);
				}
			}
				
		}
	}
}
