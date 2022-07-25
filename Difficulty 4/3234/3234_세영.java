import java.io.*;
import java.util.*;

public class D4_3234 {
	static int N, res;
	static int[] weight,sorted;
	static boolean[] isSelected;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int tc = Integer.parseInt(br.readLine());
		for(int T = 1 ; T<=tc ; T++) {
			N = Integer.parseInt(br.readLine());
			weight = new int[N];
			sorted = new int[N];
			isSelected = new boolean[N];
			
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for(int i =0 ; i < N ; i++) {
				weight[i] = Integer.parseInt(st.nextToken());
			}
			
			res = 0;
			perm(0);
			
			sb.append("#").append(T).append(" ").append(res).append("\n");
		}
		System.out.println(sb.toString());
		br.close();

	}
	
	static void perm(int cnt) {
		if(cnt == N) {
			scale(0,0,0);
		}
		
		for(int i = 0 ; i < N ; i++) {
			if(isSelected[i]) continue;
			sorted[cnt] = weight[i];		
			isSelected[i] = true;	
			perm(cnt+1);	
			isSelected[i] = false;	
		}
	}
	
	static void scale(int cnt, int left, int right) {
		if(left<right) return;
		if(cnt == N) {		
			res++;		
			return;
		}
		scale(cnt+1, left, right+sorted[cnt]);		
		scale(cnt+1, left+sorted[cnt], right);		
	}
}
