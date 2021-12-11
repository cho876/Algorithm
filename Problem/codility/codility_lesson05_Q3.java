import java.util.*;

// GenomicRangeQuery
class Solution {
    public int[] solution(String S, int[] P, int[] Q) {
        int[] count = {0,0,0,0};
        HashMap<Character, Integer> map= new HashMap<>();
        map.put('A',1);
        map.put('C',2);
        map.put('G',3);
        map.put('T',4);
        
        char[] splitStr = S.toCharArray();
        int[][] totalCount = new int[splitStr.length][4];

        for(int i=0;i<splitStr.length;i++){
            count[map.get(splitStr[i])-1]++;
            for(int j=0;j<4;j++){
                totalCount[i][j] = count[j];
            }
        }

        int[] answer = new int[P.length];
        int M = P.length;

        for(int i=0; i<M; i++){
            for(int j=0; j<4; j++){
                int end = totalCount[Q[i]][j];
                int beforeStart = P[i] == 0 ? 0 : totalCount[P[i]-1][j];
                if(end-beforeStart > 0){
                    answer[i] = j+1;
                    break;
                }
            }
        }

        return answer;
    }
}