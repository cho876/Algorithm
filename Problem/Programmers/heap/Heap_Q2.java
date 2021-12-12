import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        Arrays.sort(jobs, (j1,j2) -> j1[0]-j2[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((p1,p2) -> p1[1]-p2[1]);
        
        int curJobIndex = 0;
        int completeCnt = 0;
        int endPoint = 0;
        
        while(completeCnt < jobs.length){
            
            while(curJobIndex < jobs.length && jobs[curJobIndex][0] <= endPoint){
                pq.add(jobs[curJobIndex++]);
            }
            
            if(pq.isEmpty()){
                endPoint = jobs[curJobIndex][0];
            }else{
                int[] tmp = pq.poll();
                answer += endPoint + tmp[1]-tmp[0];
                endPoint += tmp[1];
                completeCnt++;
            }
        }
        answer = (int)Math.floor(answer/jobs.length);
        return answer;
    }
}