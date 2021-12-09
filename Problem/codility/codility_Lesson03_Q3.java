class Solution {
    public int solution(int[] A) {

        int minVal = 9999999;
        int sum = 0;

        for(int i=0;i<A.length;i++){
            sum += A[i];
        }

        int left = 0;
        int right = sum;
        for(int i=1;i<A.length;i++){
            left += A[i-1];
            right -= A[i-1];

            minVal = Math.min(minVal, Math.abs(left-right));
        }

        return minVal;
    }
}