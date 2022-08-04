import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int n = progresses.length, i = 0;
        ArrayList<Integer> list = new ArrayList<>();
        
        //int m = n-1;
        while(i < n) {
            int a = (100-progresses[i]) / speeds[i];
            int b = (100-progresses[i]) % speeds[i];
            if (b > 0) a++;
            
            int cnt = 0;
            for (int j = i; j < n; j++) {
                progresses[j] += a*speeds[j];
            }
            for (int j = i; j < n; j++) {
                if (progresses[j] < 100) break;
                cnt++;
            }
            
            list.add(cnt);
            i += cnt;
        }
        
        answer = new int[list.size()];
        for (i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}