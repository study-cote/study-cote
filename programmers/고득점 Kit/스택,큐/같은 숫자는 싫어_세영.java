import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        
        int p = arr[0]; list.add(p);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i]!=p)
                list.add(arr[i]);
            p = arr[i];
        }
        
        int n = list.size();
        answer = new int[n];
        for (int i = 0; i < n; i++)
            answer[i] = list.get(i);
        return answer;
    }
}