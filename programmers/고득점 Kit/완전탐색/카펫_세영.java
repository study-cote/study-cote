import java.util.*;

class Solution {
    static class Pos {
        int x, y;
        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int n = brown + yellow;
        ArrayList<Pos> list = new ArrayList<>();
        
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                list.add(new Pos(n/i, i));
            }
        }
        
        for (int i = 0; i < list.size(); i++) {
            int x = list.get(i).x;
            int y = list.get(i).y;
            
            if ((x+y) == brown/2+2) {
                answer[0] = x;
                answer[1] = y;
                break;
            }
        }
        return answer;
    }
}