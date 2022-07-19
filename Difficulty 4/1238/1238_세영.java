import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class D4_1238 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			
			int arr[][] = new int[101][101];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n/2; i++) {
				arr[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 1;
			}
			
			boolean visited[] = new boolean[101];
			Queue<Integer> queue = new LinkedList<>();
			
			visited[start] = true;
			for (int i = 0; i < 100; i++) {
				if (arr[start][i] == 1) {
					queue.offer(i);
					visited[i] = true;
				}
			}
			
			int max = 0;
			while(!queue.isEmpty()) {
				int size = queue.size();
				for (int i = 0; i < size; i++) {
					int m = queue.poll();
					max = Math.max(m, max);
					for (int j = 0; j < 100; j++)
						if (arr[m][j] == 1 && !visited[j]) {
							queue.offer(j);
							visited[j] = true;
						}
				}
			}
			
			sb.append("#").append(t).append(" ").append(max).append("\n");	
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

}
