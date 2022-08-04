import java.util.*;

class Solution {
    public static int solution(int[] priorities, int location) {
        int answer = 0;
        int n = priorities.length;
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            q.offer(priorities[i]);
        }
        while(!q.isEmpty()) {
            int m = q.peek();
            int cnt = 0;
            
            
            for (Integer i : q) {
                if (i > m) {
                	q.poll();
                    q.offer(m);
                    location = (location -1 + n) % n;
                    break;
                } else cnt++;
            }
            
            if (cnt == n) {
                answer++;
                if (location != 0) {
                    q.poll();
                    n--;
                    location = (location -1 + n) % n;
                } else
                    break;
            }
            
        }
        return answer;
    }
}