import java.util.*;

class Solution {
    public int solution(int N) {
        String data = Integer.toBinaryString(N);

        int curCnt = 0;
        int maxCnt = 0;
        boolean isStart = false;

        for(int i=0;i<data.length();i++){
            char ch = data.charAt(i);
            if(ch == '1'){
                if(isStart){
                    maxCnt = Math.max(curCnt, maxCnt);
                    curCnt = 0;
                }else{
                    isStart = true;
                    curCnt = 0;
                }
            }else{
                curCnt += 1;
            }
        }
        return maxCnt;
    }
}