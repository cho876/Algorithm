// CountDiv
class Solution {
    public int solution(int A, int B, int K) {
        int answer = 0;
        int left = 0;
        int right = B/K;

        if(A % K == 0){
            left = A/K;
        }else{
            left = A/K + 1;
        }
        
        answer = right-left+1;
        
        return answer;
    }
}