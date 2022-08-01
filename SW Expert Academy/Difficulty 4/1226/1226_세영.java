import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1226 {
	static int arr[][], res;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static boolean[][] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			arr = new int[16][16];
			visited = new boolean[16][16];
			int x = 0, y = 0;
			res = 0;
			
			for (int i = 0; i < 16; i++) {
				char[] num = br.readLine().toCharArray();
				for (int j = 0; j < 16; j++) {
					arr[i][j] = num[j]-'0';
					if (arr[i][j] == 2) {
						x = i;
						y = j;
					}
				}
			}
			
			visited[x][y] = true;
			dfs(x, y);
			
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}
	
	static void dfs(int x, int y) {
		if (arr[x][y] == 3) {
			res = 1;
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx > 0 && nx < 15 && ny > 0 && ny < 15 && arr[nx][ny]!=1 && visited[nx][ny]==false) {
				visited[nx][ny] = true;
				dfs(nx, ny);
				visited[nx][ny] = false;
			}
		}
	}

}
