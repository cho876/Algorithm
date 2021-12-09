import java.util.*;

// PermCheck
class Solution {
    public int solution(int[] A) {
        int answer = 1;

        int curVal = 1;

        Arrays.sort(A);

        for(int num : A){
            if(num != curVal){
                answer = 0;
                break;
            }
            curVal++;
        }

        return answer;
    }
}