import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class D4_1258 {
	static int arr[][], n;
	
	static class RC implements Comparable<RC>{
		int row, col, mul;
		
		public RC(int row, int col) {
			this.row = row;
			this.col = col;
			this.mul = row*col;
		}
		
		@Override
		public int compareTo(RC rc) {
			if (rc.mul < mul) {
				return 1;
			} else if (rc.mul > mul) {
				return -1;
			} else {
				if (rc.row < row) {
					return 1;
				} else {
					return -1;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			boolean visited[][] = new boolean[n][n];
			arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			
			ArrayList<RC> rc = new ArrayList<>();
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!visited[i][j] && arr[i][j] != 0) {
						cnt++;
						int row=0, col=0;
						for (int r = i; r < n; r++) {
							for (int c = j; c < n; c++) {
								visited[r][c] = true;
								if (c==n-1 || arr[r][c+1]==0) {
									col = c;
									break;
								}
							}
							if (r==n-1 || arr[r+1][j]==0) {
								row = r;
								break;
							}
						}
						rc.add(new RC(row-i+1, col-j+1));
					}
				}
			}
			
			Collections.sort(rc);
			
			sb.append("#").append(t).append(" ").append(cnt).append(" ");
			for (int i = 0; i < rc.size(); i++) {
				sb.append(rc.get(i).row).append(" ").append(rc.get(i).col).append(" ");
			}
			sb.append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}
}
