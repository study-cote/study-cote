import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_6109 {
	static int grid[][];
	static int result[][];
	static int T;
	static int N;
	static String dir;
	
	static void Game() {
		switch(dir) {
		case "up":
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N - 1; i++) {
					if (grid[i][j] == 0) continue;
					
					int k = i + 1;
					while (k < N - 1 && grid[k][j] == 0) k++;
					
					if (grid[i][j] == grid[k][j]) {
						grid[i][j] *= 2;
						grid[k][j] = 0;
					}
				}
				int idx = 0;
				for (int i = 0; i < N; i++) {
					if (grid[i][j] != 0) result[idx++][j] = grid[i][j];
				}
			}
			break;
		case "down":
			for (int j = 0; j < N; j++) {
				for (int i = N - 1; i > 0; i--) {
					if (grid[i][j] == 0) continue;
					
					int k = i - 1;
					while (k > 0 && grid[k][j] == 0) k--;
					
					if (grid[i][j] == grid[k][j]) {
						grid[i][j] *= 2;
						grid[k][j] = 0;
					}
				}
				int idx = N - 1;
				for (int i = N - 1; i >= 0; i--) {
					if (grid[i][j] != 0) result[idx--][j] = grid[i][j];
				}
			}
			break;
		case "left":
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N - 1; j++) {
					if (grid[i][j] == 0) continue;
					
					int k = j + 1;
					while (k < N - 1 && grid[i][k] == 0) k++;
					
					if (grid[i][j] == grid[i][k]) {
						grid[i][j] *= 2;
						grid[i][k] = 0;
					}
				}
				int idx = 0;
				for (int j = 0; j < N; j++) {
					if (grid[i][j] != 0) result[i][idx++] = grid[i][j];
				}
			}
			break;
		case "right":
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j > 0; j--) {
					if (grid[i][j] == 0) continue;
					
					int k = j - 1;
					while (k > 0 && grid[i][k] == 0) k--;
					
					if (grid[i][j] == grid[i][k]) {
						grid[i][j] *= 2;
						grid[i][k] = 0;
					}
				}
				int idx = N - 1;
				for (int j = N - 1; j >= 0; j--) {
					if (grid[i][j] != 0) result[i][idx--] = grid[i][j];
				}
			}
			break;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			dir = st.nextToken();
			
			grid = new int[N][N];
			result = new int[N][N];
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					grid[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			Game();
			
			bw.write("#" + test_case);
			bw.newLine();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					bw.write(result[i][j] + " ");
				}
				bw.newLine();
			}
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
}
