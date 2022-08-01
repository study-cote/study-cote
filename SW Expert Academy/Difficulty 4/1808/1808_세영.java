import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class D4_1808 {
	static int[] nums;
	static int target;
	static int min;
	public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int testNum = Integer.parseInt(br.readLine());
        for(int test=1; test<=testNum; test++) {
			String[] temp = br.readLine().split(" ");
			nums = new int[10];
			min = Integer.MAX_VALUE;
			for(int i=0; i<10; i++)
				nums[i] = Integer.parseInt(temp[i]);

			target = Integer.parseInt(br.readLine());
			
			int b = check(target);
			if(b != 0){
				b += 1;
				System.out.println("#" + test + " " + b);
				continue;
			}

			solve(target, 0);
			
			if(min == Integer.MAX_VALUE)
				min = -1;
			else
				min += 1;
			System.out.println("#" + test + " " + min);	
        }
        			  
		br.close();
	}
	
	public static int solve(int target, int depth){
		int result = Integer.MAX_VALUE;
		int b = check(target);
		
		if(b != 0)
			return b;

		for(int i=2, end=(int)Math.sqrt(target)+1; i< end; i++){
			if(target % i == 0){
				int a = check(i);
				if(a != 0){
					a = a + 1;
					b = solve(target/i, depth+1);
					
					if(b != Integer.MAX_VALUE){
						int r = a+b;
						if(r < result)
							result = r;
						
						if(result < min && target == D4_1808.target)
							min = result;
					}
				}
			}
		}
		return result;
	}

	public static int check(int num){
		int t = 0;
		int len = 1;

		if(num >= 10){
			while(true){
				t = num % 10;
				num /= 10;
				len++;
				if(nums[t] == 0)
					return 0;
				if(num < 10)
					break;
			}
		}
		
		if(nums[num] == 0) return 0;

		return len;
	}
}