import java.util.*;

// MaxProfit
class Solution {
    public int solution(int[] A) {
        if(A.length == 0){
            return 0;
        }
        
        int minVal = Integer.MAX_VALUE;
        int answer = Integer.MIN_VALUE;

        for(int num : A){
            if(minVal > num){
                minVal = num;
            }
            if(answer < num-minVal){
                answer = num-minVal;
            }
        }
        return answer;
    }
}