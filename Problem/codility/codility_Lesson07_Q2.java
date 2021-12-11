import java.util.*;

// Fish
class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Stack<Integer> stk = new Stack<>();

        for(int i=0;i<A.length;i++){
            if(B[i] == 1){
                stk.push(A[i]);
            }else{
                while(!stk.isEmpty()){
                    int curWeight = stk.peek();

                    if(curWeight > A[i]){
                        break;
                    }else{
                        stk.pop();
                    }
                }
                if(stk.isEmpty()){
                    answer++;
                }
            }
        }
        return answer + stk.size();
    }
}