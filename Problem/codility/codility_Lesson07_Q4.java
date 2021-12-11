import java.util.*;

class Solution {
    public int solution(int[] H) {
        int answer = 0;

        Stack<Integer> stk = new Stack<>();
        stk.push(H[0]);

        for(int i=1;i<H.length;i++){
            if(stk.isEmpty()){
                stk.push(H[i]);
            }else{
                while(!stk.isEmpty()){
                    int lastWeight = stk.peek();

                    if(lastWeight == H[i]){
                        break;
                    }else if(lastWeight < H[i]){
                        stk.push(H[i]);
                        break;
                    }else{
                        stk.pop();
                        answer++;
                    }
                }
                if(stk.isEmpty()){
                    stk.push(H[i]);
                }
            }
        }
        return answer + stk.size();
    }
}