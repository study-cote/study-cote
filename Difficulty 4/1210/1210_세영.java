import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1210 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			int arr[][] = new int[100][100];
			for (int i = 0; i < 100; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 100; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int x = 0;
			for (int i = 0; i < 100; i++)
				if (arr[99][i] == 2) {
					x = i;
					break;
				}
			
			int i = 98, dir = 0;
			while(true) {
				if (i == 0)
					break;
				
				if (x-1 >= 0 && arr[i][x-1] == 1 && dir != 2) { // 왼쪽
					x = x-1;
					dir = 1;
				}
				else if (x+1 < 100 && arr[i][x+1] == 1 && dir != 1) { // 오른쪽 
					x = x+1;
					dir = 2;
				}
				else { // 위쪽
					i = i-1;
					dir = 0;
				}
			}
			
			sb.append("#").append(t).append(" ").append(x).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

}
