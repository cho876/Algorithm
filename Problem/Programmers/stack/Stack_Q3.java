import java.util.*;

// 다리를 지나는 트럭
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> que = new LinkedList<>();
        int curSum = 0;
        
        for(int i=0;i<truck_weights.length;i++){
            int curWeight = truck_weights[i];
            
            while(true){
                if(que.isEmpty()){
                    que.add(curWeight);
                    answer++;
                    curSum+=curWeight;
                    break;
                }else if(que.size() == bridge_length){
                    int removeVal = que.poll();
                    curSum -= removeVal;
                }else{
                    if(curSum + curWeight <= weight){
                        que.add(curWeight);
                        curSum += curWeight;
                        answer++;
                        break;
                    }else{
                        que.add(0);
                        answer++;
                    }
                }
            }
        }
        return answer+bridge_length;
    }
}