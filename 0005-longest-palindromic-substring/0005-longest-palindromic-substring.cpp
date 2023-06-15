class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
        int mx_len=1,idx=0;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=i+gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j] && mx_len < gap+1){
                    mx_len=gap+1;
                    idx=i;
                }
            }
        }
        return s.substr(idx,mx_len);
    }
};