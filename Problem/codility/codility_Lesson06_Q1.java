import java.util.*;

// Distict
class Solution {
    public int solution(int[] A) {
        int answer = 0;

        if(A.length == 0){
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int num : A){
            if (map.get(num) == null){
                map.put(num,1);
            }else{
                map.put(num,map.get(num)+1);
            }
        }

        answer = map.size();

        return answer;
    }
}