import java.util.*;

// MaxProductOfThree
class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);

        int endIdx = A.length-1;
        int case1 = A[0] * A[1] * A[2];
        int case2 = A[endIdx] * A[endIdx-1] * A[endIdx-2];
        int case3 = A[0] * A[1] * A[endIdx];
        int case4 = A[endIdx] * A[endIdx-1] * A[0];

        int left = Math.max(case1,case2);
        int right = Math.max(case3, case4);

        int answer = Math.max(left,right);

        return answer;
    }
}