import java.util.*;

// Dominator
class Solution {
    public int solution(int[] A) {
        HashMap<Integer,Integer> map = new HashMap<>();
        
        if(A.length == 0){
            return -1;
        }

        for(int i=0;i<A.length;i++){
            if(map.get(A[i]) == null){
                map.put(A[i],1);
            }else{
                map.put(A[i],map.get(A[i])+1);
            }
        }

        int value = -1;
        int half = A.length/2;
        int answer = -1;

        for(int key : map.keySet()){
            if(map.get(key) > half){
                value = key;
                break;
            }
        }
        for(int i=0;i<A.length;i++){
            if(A[i] == value){
                answer = i;
                break;
            }
        }

        return answer;
    }
}