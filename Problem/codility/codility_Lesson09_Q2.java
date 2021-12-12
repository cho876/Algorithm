import java.util.*;


//MaxSliceSum
class Solution {
    public int solution(int[] A) {
        int answer = A[0];
        int localAnswer = A[0];

        for(int i=1;i<A.length;i++){
            localAnswer = Math.max(A[i], A[i]+localAnswer);
            answer = Math.max(localAnswer, answer);
        }

        return answer;
    }
}