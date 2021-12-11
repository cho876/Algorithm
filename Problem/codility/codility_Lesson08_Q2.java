import java.util.*;

// EquiLeader
class Solution {
    public int solution(int[] A) {
        int answer = 0;
        HashMap<Integer,Integer> map = new HashMap<>();

        for(int i=0;i<A.length;i++){
            if(map.get(A[i]) == null){
                map.put(A[i],1);
            }else{
                map.put(A[i],map.get(A[i])+1);
            }
        }

        int maxKey = 0;
        int maxValue = 0;

        for(int key : map.keySet()){
            if(maxValue < map.get(key)){
                maxValue = map.get(key);
                maxKey = key;
            }
        }

        int count = 0;
        Vector<Integer> vec = new Vector<>();

        for(int i=0;i<A.length;i++){
            if(A[i] == maxKey){
                count++;
            }
            vec.add(count);
        }

        for(int i=0; i<A.length-1;i++){
            int leftCount = vec.elementAt(i);
            int rightCount = vec.lastElement()-leftCount;

            int leftIndex = (i+1)/2 + 1;
            int rightIndex = ((A.length-(i+1))/2) + 1;

            if((leftCount >= leftIndex) && (rightCount >= rightIndex)){
                answer++;
            }
        }
        return answer;
    }
}