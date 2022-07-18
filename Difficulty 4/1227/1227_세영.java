import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class D4_1227 {
	static int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
	static int arr[][], res, ex, ey;
	static boolean visited[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			visited = new boolean[100][100];
			arr = new int[100][100];
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					arr[i][j] = br.read()-'0';
					if (arr[i][j]==3) {
						ex = i; ey = j;
					}
				}
			}
			res = 0;
			bfs(1, 1);
			
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}
	static void bfs(int x, int y) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {x, y});
		
		while (!q.isEmpty()) {
			int[] pos = q.poll();
			if (pos[0] == ex && pos[1] == ey) {
				res = 1;
				return;
			}
			visited[pos[0]][pos[1]] = true;
			
			for (int i = 0; i < 4; i++) {
				int nx = pos[0] + dx[i];
				int ny = pos[1] + dy[i];
				
				if (nx > 0 && nx < 99 && ny > 0 && ny < 99 && arr[nx][ny] != 1 && !visited[nx][ny])
					q.offer(new int[] {nx, ny});
			}
		}
	}
}
