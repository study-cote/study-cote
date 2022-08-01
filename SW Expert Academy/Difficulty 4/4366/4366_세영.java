import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D4_4366 {
	static int arr2[], arr3[], n, m;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			char c[] = br.readLine().toCharArray();
			n = c.length;
			arr2 = new int[n];
			for (int i = 0; i < n; i++)
				arr2[i] = c[i]-'0';
			
			c = br.readLine().toCharArray();
			m = c.length;
			arr3 = new int[m];
			for (int i = 0; i < m; i++)
				arr3[i] = c[i]-'0';
			
			ArrayList<Integer> list = new ArrayList<>();
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum = 0;
				for (int j = 0; j < n; j++) {
					if (j == i) {
						if (arr2[j] == 0) {
							sum += Math.pow(2, (n-1)-j);
						}
					} else {
						sum += arr2[j] * Math.pow(2, (n-1)-j);
					}
				}
				list.add(sum);
			}
			
			int result = 0;
			outer:for (int i = 0; i < m; i++) {
				sum = 0;
				for (int j = 0; j < m; j++) {
					if (j != i)
						sum += arr3[j] * Math.pow(3, (n-1)-j);
				}
				int res[] = new int[3];
				for (int j = 0; j < 3; j++) {
					res[i] = sum;
					res[i] += j * Math.pow(3, (n-1)-i);
					
					if (list.contains(res[i])) {
						result = res[i];
						break outer;
					}
				}
			}
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

}
