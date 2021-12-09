import java.util.*;

class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);

        int val = 1;

        for(int i=0;i<A.length;i++){
            if(A[i] != val){
                return val;
            }else{
                val++;
            }
        }
        return val;
    }
}