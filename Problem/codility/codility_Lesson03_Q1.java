class Solution {
    public int solution(int X, int Y, int D) {

        int answer = ((Y-X) / D);

        if(((Y-X) % D) != 0){
            answer+=1;
        }
        
        return answer;
    }
}
