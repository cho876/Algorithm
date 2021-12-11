import java.util.*;


class Solution {
    public int solution(int[] A) {
        int answer = 0;

        if(A.length < 3){
            return 0;
        }
        
        Arrays.sort(A);

        for(int i=0;i<A.length-2;i++){
            long num1=A[i], num2=A[i+1], num3=A[i+2];

            if(num1+num2 > num3){
                answer = 1;
                break;
            }
        }
        return answer;
    }
}