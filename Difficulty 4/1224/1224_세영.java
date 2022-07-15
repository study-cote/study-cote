import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class D4_1224 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 1; t++) {
			Stack<Character> stack = new Stack<>();
			int n = Integer.parseInt(br.readLine());
			char[] arr = new char[n];
			arr = br.readLine().toCharArray();
			
			int res = 0;
			int a = 0, b = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] == ')') {
					int sum = 0;
					
					while (true) {
						char c = stack.pop();
						
						if (c == '(') break;
						else if (c=='*') {
							b = (int)stack.pop();
							res -= a;
							res += a*b;
						} else if (c!='+') {}
					}
				}
				else if (arr[i] == '*') {
					int a = (int)stack.pop();
					int b = (int)arr[++i];
					stack.push((char)(a*b));
				}
				else if (arr[i] != '+')
					stack.push(arr[i]);
			}
			
			while(!stack.isEmpty()) {
				res += (int)stack.pop();
			}
			
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

}
