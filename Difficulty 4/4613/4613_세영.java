import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_4613 {
	static int n, m;
	static char arr[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			
			arr = new char[n][m];
			for (int i = 0; i < n; i++) {
				arr[i] = br.readLine().toCharArray();
			}
			
			int w=0, b=0, r=0, min=2500;
			for (int i = 0; i < n-2; i++) {
				w += count(i, 'W');
				
				b=0;
				for (int j = i+1; j < n-1; j++) {
					b += count(j, 'B');
					
					r=0;
					for (int k = j+1; k < n; k++) {
						r += count(k, 'R');
					}
					
					min = Math.min(min, w+b+r);
				}
			}
			sb.append("#").append(t).append(" ").append(min).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
	
	static int count(int row, char c) {
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			if (arr[row][i] != c) cnt++;
		}
		
		return cnt;
	}
}
