import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D4_1211 {
	static int arr[][], min=10000, idx, d, x, y;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			for (int i = 0; i < 100; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 100; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			
			for (int i = 0; i < 100; i++) {
				if (arr[0][i] == 1) {
					x = 0; y = i; d = 0;
					int n = ladder();
					if (n <= min) {
						idx = i;
						min = n;
					}
				}
			}
			sb.append("#").append(t).append(" ").append(idx).append("\n");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
	
	static int ladder() {
		int sum = 0;
		while(true) {
			switch(d) {
			case 0:
				sum += leftOrRight(x, y);
				break;
			case 1:
				sum += goLeft(x, y);
				break;
			case 2:
				sum += goRight(x, y);
				break;
			}
			if (x==99) break;
		}
		return sum;
	}
	
	static int leftOrRight(int a, int b) {
		int l=0, r=0;
		
		if (b > 0) {
			for (int i = a+1; i < 100; i++)
				if (arr[i][b-1] == 1) {
					l = i;
					break;
				}
		}
		
		if (b < 99) {
			for (int i = a+1; i < 100; i++)
				if (arr[i][b+1] == 1) {
					r = i;
					break;
				}
		}
		
		if (l < r) {
			x = l; d = 1;
			return l;
		} else {
			x = r; d = 2;
			return r;
		}
	}
	
	static int goLeft(int a, int b) {
		int res = 0;
		while(true) {
			if (b < 0 || arr[a][b]==0)
				break;
			b--; res++;
		}
		y = b+1; d = 0;
		return res-1;
	}
	
	static int goRight(int a, int b) {
		int res = 0;
		while(true) {
			if (b > 99 || arr[a][b]==0)
				break;
			b++; res++;
		}
		y = b-1; d = 0;
		return res-1;
	}
}
