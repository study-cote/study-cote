import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D4_4050 {
	public static int N, answer;
	public static int[] clothes;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st = null;		
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; ++tc) {
			N = Integer.parseInt(br.readLine());
			
			clothes = new int[N];
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; ++i) {
				clothes[i] = Integer.parseInt(st.nextToken());
			}
			
			Arrays.sort(clothes);
			
			answer = 0;
			
			int idx = N - 1;
			int cnt = 1;
			while (idx >= 0) {
				if (cnt % 3 == 0) {
					cnt = 1;
					idx--;
					continue;
				}
				
				answer += clothes[idx--];
				cnt++;
			}
			
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}
		
		System.out.println(sb);
	}
}