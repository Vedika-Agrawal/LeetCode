class Solution {
public:
    int maxConsecutiveAnswers(string s , int k) {
        int st = 0; int i= 0;
        int t =0 , f=0 ;
        int ans = 0;
        while(i<s.size()){
           
            if(s[i]=='T')t++;
            else f++;
            int mini = min(t,f);
            while(mini>k){
               if(s[st]=='T')t--;
               else f--;
               mini = min(t,f);
                st++;
            }
            ans = max(ans, t+f);
            i++;
            
        }
        return ans;
    }
};