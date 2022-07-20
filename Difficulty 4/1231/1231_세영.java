import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1231 {
	static int n;
	static char arr[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			n = Integer.parseInt(br.readLine());
			arr = new char[n+1];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				arr[Integer.parseInt(st.nextToken())] = st.nextToken().charAt(0);
			}
			
			System.out.printf("#%d ", t);
			inOrder(1);
			System.out.println();
		}
	}
	static void inOrder(int root) {
		if (root > n) return;
		
		inOrder(root*2);
		System.out.print(arr[root]);
		inOrder(root*2+1);
	}
}
