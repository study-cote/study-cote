import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1249 {
	static int arr[][], min, n;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static boolean[][] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n][n];
			visited = new boolean[n][n];
			
			for (int i = 0; i < n; i++) {
				char[] num = br.readLine().toCharArray();
				for (int j = 0; j < n; j++) {
					arr[i][j] = num[j]-'0';
					min += arr[i][j];
				}
			}
			
			visited[0][0] = true;
			dfs(0, 0, 0);
			
			sb.append("#").append(t).append(" ").append(min).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}
	
	static void dfs(int x, int y, int cnt) {
		if (cnt > min)
			return;
		
		if (x == n-1 && y == n-1) {
			min = cnt;
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny]==false) {
				visited[nx][ny] = true;
				dfs(nx, ny, cnt+arr[nx][ny]);
				visited[nx][ny] = false;
			}
		}
	}

}
