import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int n = sizes.length;
        int hmax = 0, wmax = 0;
        
        for (int i = 0; i < n; i++) {
            int h=0, w=0;
            if (sizes[i][0] > sizes[i][1]) {
                h = sizes[i][0]; w = sizes[i][1];
            } else {
                h = sizes[i][1]; w = sizes[i][0];
            }
            
            hmax = Math.max(hmax, h);
            wmax = Math.max(wmax, w);
        }
        answer = hmax * wmax;
        return answer;
    }
}