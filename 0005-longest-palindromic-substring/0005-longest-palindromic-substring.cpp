class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 1 , idx= 0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(), 0));
        
        for(int gap =0;gap<s.size();gap++){
            for(int i = 0 , j= gap+i ; j<s.size(); j++, i++){
                if(gap==0)dp[i][j]=1;
                else if(gap==1 && s[j] == s[i] && s[j-1]==s[j]){
                    dp[i][j]=1;
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=  dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==1 && mx < gap+1){
                    mx = gap+1;
                    idx = i;
                }
            }
        }
        return s.substr(idx, mx);
    }
};