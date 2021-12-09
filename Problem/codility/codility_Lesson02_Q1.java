class Solution {
    public int[] solution(int[] A, int K) {
        int[] B = A.clone();

        for(int j=0;j<B.length;j++){
            B[(j+K)%B.length] = A[j];
        }

        return B;
    }
}