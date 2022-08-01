import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D4_2819 {
	static int arr[][];
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static ArrayList<Integer> list;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			arr = new int[4][4];
			list = new ArrayList<>();
			
			for (int i = 0; i < 4; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 4; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					dfs(i, j, 0, arr[i][j] * (int)Math.pow(10, 6));
				}
			}
			
			sb.append("#").append(t).append(" ").append(list.size()).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}
	
	static void dfs(int x, int y, int d, int sum) {
		if (d == 6) {
			if (!list.contains(sum))
				list.add(sum);
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
				dfs(nx, ny, d+1, sum + arr[nx][ny]*(int)Math.pow(10, 5-d));
			}
		}
	}

}
