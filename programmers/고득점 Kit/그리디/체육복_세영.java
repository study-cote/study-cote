import java.util.*;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int check[] = new int[n];
        
        for (int i = 0; i < n; i++)
            check[i] = 1;
        
        for (int i = 0; i < lost.length; i++) 
            check[lost[i]-1] -= 1;
        for (int i = 0; i < reserve.length; i++)
            check[reserve[i]-1] += 1;
        
        Arrays.sort(reserve);
        for (int i = 0; i < reserve.length; i++) {
            int m = reserve[i]-1;
            if (check[m] == 1) continue;
            
            if (m > 0 && check[m-1]==0) { // left
                check[m] -= 1;
                check[m-1] += 1;
            }
            else if (m < (n-1) && check[m+1]==0) { // right
                check[m] -= 1;
                check[m+1] += 1;
            }
        }
        for (int i = 0; i < n; i++)
            if (check[i] > 0)
                answer++;
        
        return answer;
    }
}