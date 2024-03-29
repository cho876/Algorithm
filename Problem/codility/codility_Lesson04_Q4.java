import java.util.*;

class Solution {
    public int solution(int[] A) {
        HashSet<Integer> set = new HashSet<>();

        for(int i=0;i<A.length;i++){
            set.add(A[i]);
        }

        for(int i=1;i<Integer.MAX_VALUE;i++){
            if(!set.contains(i)){
                return i;
            }
        }
        return -1;
    }
}