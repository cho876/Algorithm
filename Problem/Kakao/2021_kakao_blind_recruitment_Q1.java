// 신규 아이디 추천
class Solution {
    public String solution(String new_id) {
        String answer = "";
        
        answer = new_id.toLowerCase();
        answer = answer.replaceAll("[^-_.0-9a-z]","");
        answer = answer.replaceAll("[.]{2,}",".");
        answer = answer.replaceAll("^[.]|[.]$","");        
        answer = answer.length() == 0 ? "a" : answer;
        answer = answer.length() >= 16 ? answer.substring(0,15) : answer;
        answer = answer.replaceAll("[.]$","");
        
        if(answer.length() <= 2){
            while(answer.length() < 3){
                answer += answer.charAt(answer.length()-1);
            }
        }
        return answer;
    }
}