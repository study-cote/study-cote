import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1232 {
	static class Node {
		String op;
		double num;
		int left;
		int right;
		
		public Node(String op, double n, int l, int r) {
			this.op = op;
			this.num = n;
			this.left = l;
			this.right = r;
		}
	}
	
	public static int N;
	public static Node[] tree = new Node[1001];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		for (int t = 1; t <= 10; t++) {
			N = Integer.parseInt(br.readLine());
			
			for (int i = 1; i <= N; ++i) {
				st = new StringTokenizer(br.readLine(), " ");
				st.nextToken();
				
				if (st.countTokens() > 1) {
					tree[i] = new Node(st.nextToken(), 0, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
				}
				else {
					tree[i] = new Node("", Double.parseDouble(st.nextToken()), -1, -1);
				}
			}
			
			for (int i = N; i > 0; i--) {
				if (tree[i].left > 0 && tree[i].right > 0) {
					if (tree[i].op.equals("+")) {
						tree[i].num = tree[tree[i].left].num + tree[tree[i].right].num;
					}
					else if (tree[i].op.equals("-")) {
						tree[i].num = tree[tree[i].left].num - tree[tree[i].right].num;
					}
					else if (tree[i].op.equals("*")) {
						tree[i].num = tree[tree[i].left].num * tree[tree[i].right].num;
					} 
					else {
						tree[i].num = tree[tree[i].left].num / tree[tree[i].right].num;
					}
				}
			}
			
			sb.append("#").append(t).append(" ").append((int) tree[1].num).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}