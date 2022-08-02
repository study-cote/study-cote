import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {}, ansB = {1, 3, 4, 5}, ansC = {3, 1, 2, 4, 5};
        int n = answers.length;
        int[] score = new int[3];
        
        for (int i = 0; i < n; i++) {
            int m = answers[i];
            if (m == (i%5)+1)
                score[0]++;
            
            int b = 2;
            if (i%2 == 1) 
                b = ansB[(i/2)%4];
            if (m == b)
                score[1]++;
            
            if (m == ansC[(i/2)%5])
                score[2]++;
        }
        
        int max = Math.max(score[0], Math.max(score[1], score[2]));
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 3; i++)
            if (max == score[i])
                list.add(i+1);
        
        n = list.size();
        answer = new int[n];
        for (int i = 0; i < n; i++)
            answer[i] = list.get(i);
        
        return answer;
    }
}