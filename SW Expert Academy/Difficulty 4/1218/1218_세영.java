import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class D4_1218 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine());
			char arr[] = new char[n];
			arr = br.readLine().toCharArray();
			
			int check = 0, res = 0;
			char c;
			Stack<Character> stack = new Stack<>();
			for (int i = 0; i < n; i++) {
				switch(arr[i]) {
				case '[':
				case '{':
				case '(':
				case '<':
					stack.push(arr[i]);
					break;
				case ']':
					c = stack.pop();
					if (c != '[')
						check++;
					break;
				case '}':
					c = stack.pop();
					if (c != '{')
						check++;
					break;
				case ')':
					c = stack.pop();
					if (c != '(')
						check++;
					break;
				case '>':
					c = stack.pop();
					if (c != '<')
						check++;
					break;
				}
				if (check > 0)
					break;
			}
			
			if (stack.isEmpty() && check==0)
				res = 1;
			
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();

	}

}

