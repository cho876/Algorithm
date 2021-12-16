// 문자열 압축
class Solution {
    public int solution(String s) {
        int answer = Integer.MAX_VALUE;
        
        for(int i=1;i<=s.length();i++){
            int cnt = 1;
            String str = "";
            String tmp = "";
            
            for(int j=0;j<s.length()/i;j++){
                if(tmp.equals(s.substring((i*j),(i*j)+i))){
                    cnt++;
                    continue;
                }
                
                if(cnt>1){
                    str += cnt+tmp;
                    cnt = 1;
                }else{
                    str += tmp;
                }
                tmp = s.substring((i*j),(i*j)+i);
            }
            
            if(cnt > 1){
                str += cnt+tmp;
            }else{
                str += tmp;
            }
            
            if(s.length()%i != 0){
                str += s.substring(s.length()-s.length()%i, s.length());
            }
            answer = Math.min(answer, str.length());
        }
        return answer;
    }
}