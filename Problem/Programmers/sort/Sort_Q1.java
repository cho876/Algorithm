import java.util.*;

// K번째 수
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for(int i=0;i<commands.length;i++){
            int idx = 0;

            int[] res = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
            Arrays.sort(res);
            answer[i] = res[commands[i][2]-1];
        }
        return answer;
    }
}