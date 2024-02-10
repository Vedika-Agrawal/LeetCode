class Solution {
public:

    int countSubstrings(string s) {
        int n =s.size();
        int cnt = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int gap= 1; gap<=n;gap++){
            for(int i=0;i+gap<=n;i++){
                int j = i + gap -1;
                if(i==j) dp[i][j]= 1;
                else if(i==j-1 )dp[i][j] = s[i]==s[j] ? 1 :0;
                else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]) ? 1 : 0;
                }
                cnt += dp[i][j];
            }
            
        }
        return cnt;
    }
};