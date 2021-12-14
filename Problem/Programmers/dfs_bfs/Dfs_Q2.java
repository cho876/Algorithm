
// 네트워크
class Solution {
    boolean[] isVisited;
    
    public void dfs(int n, int[][] computers, int curIdx){
        if(isVisited[curIdx]){
            return;
        }
        isVisited[curIdx] = true;
        
        for(int i=0;i<computers[curIdx].length;i++){
            if(computers[curIdx][i] == 1 && !isVisited[i]){
                dfs(n, computers, i);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        isVisited = new boolean[n];
        
        for(int i=0;i<computers.length;i++){
            if(!isVisited[i]){
                dfs(n, computers, i);
                answer++;
            }
        }
        
        return answer;
    }
}