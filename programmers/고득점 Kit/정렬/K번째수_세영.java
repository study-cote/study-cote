import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int n = commands.length;
        int[] answer = new int[n];
        
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            for (int j = commands[i][0]-1; j < commands[i][1]; j++)
                list.add(array[j]);
            
            Collections.sort(list);
            answer[i] = list.get(commands[i][2]-1);
        }
        
        return answer;
    }
}