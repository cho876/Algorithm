// MaxCounters
class Solution {
    public int[] solution(int N, int[] A) {

        int[] answer = new int[N];
        int maxValue = 0;
        int tmpValue = 0;


        for(int i=0;i<A.length;i++){
            if(A[i] > N){
                maxValue = tmpValue;
                continue;
            }

            if(answer[A[i]-1] < maxValue){
                answer[A[i]-1] = maxValue;
            }
            answer[A[i]-1]++;

            if(answer[A[i]-1] > tmpValue){
                tmpValue = answer[A[i]-1];
            }
        }

        for(int i=0;i<answer.length;i++){
            if(answer[i] < maxValue){
                answer[i] = maxValue;
            }
        }
        return answer;
    }
}