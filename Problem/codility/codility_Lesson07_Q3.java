import java.util.*;

// Nesting
class Solution {
    public int solution(String S) {
        int answer = 1;
        Stack<Character> stk = new Stack<>();
        char[] chArr = S.toCharArray();

        for(int i=0;i<chArr.length;i++){
            if(chArr[i] == '(' || chArr[i] == '{' || chArr[i] == '['){
                stk.push(chArr[i]);
            }else{
                if(stk.isEmpty()){
                    answer = 0;
                    break;
                }else{
                    char ch = stk.pop();

                    if(ch == '(' && chArr[i] != ')'){
                        answer = 0;
                        break;
                    }else if(ch == '{' && chArr[i] != '}'){
                        answer = 0;
                        break;
                    }else if(ch == '[' && chArr[i] != ']'){
                        answer = 0;
                        break;
                    }
                }
            }
        }
        return answer;
    }
}