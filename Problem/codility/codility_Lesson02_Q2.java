import java.util.*;

class Solution {
    public int solution(int[] A) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

        for(int i=0;i<A.length;i++){
            if(map.get(A[i]) == null){
                map.put(A[i],1);
            }else{
                map.put(A[i],map.get(A[i])+1);
            }
        }

        int res = 0;
        for(int key : map.keySet()){
            if(map.get(key) % 2 != 0){
                res = key;
            }
        }
        return res;
    }
}