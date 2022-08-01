import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int n = nums.length;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (list.contains(nums[i])) continue;
            list.add(nums[i]);
        }
        
        if (list.size() >= n/2)
            answer = n/2;
        else
            answer = list.size();
        return answer;
    }
}