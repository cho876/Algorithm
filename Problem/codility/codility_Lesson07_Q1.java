import java.util.*;

// Brackets
class Solution {
    public int solution(String S) {
        int answer = 1;

        Stack<Character> stk = new Stack<>();
        char[] charArr = S.toCharArray();

        for(int i=0;i<charArr.length;i++){
            if(charArr[i] == '(' || charArr[i] == '{' || charArr[i] == '['){
                stk.add(charArr[i]);
            }else{
                if(stk.isEmpty()){
                    answer = 0;
                    break;
                }
                else{
                    char curCh = stk.pop();

                    if(curCh == '(' && charArr[i] != ')'){
                        answer = 0;
                        break;
                    }
                    if(curCh == '{' && charArr[i] != '}'){
                        answer = 0;
                        break;
                    }
                    if(curCh == '[' && charArr[i] != ']'){
                        answer = 0;
                        break;
                    }
                }
            }
        }

        if(!stk.isEmpty()){
            answer = 0;
        }
        
        return answer;
    }
}