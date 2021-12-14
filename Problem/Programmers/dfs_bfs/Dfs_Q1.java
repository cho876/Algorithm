
// 타겟 넘버
class Solution {
    int answer = 0;
    
    public void dfs(int[] numbers, int target, int curSum, int curIdx){
        if(curIdx == numbers.length){
            if(target == curSum){
                answer++;
            }
        }else{
            dfs(numbers,target,curSum+numbers[curIdx],curIdx+1);
            dfs(numbers,target,curSum-numbers[curIdx],curIdx+1);
        }
    }
    public int solution(int[] numbers, int target) {
        
        dfs(numbers, target, 0, 0);
        return answer;
    }
}