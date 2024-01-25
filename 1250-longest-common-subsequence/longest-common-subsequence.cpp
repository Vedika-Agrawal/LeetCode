class Solution {
public:
    int solve(string &s, string &t, int i, int j,   vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] =  1 + solve(s, t, i+1, j+1,dp);
        }
        int a = solve(s, t, i+1, j,dp);
        int b = solve(s, t, i,j+1,dp);
        return dp[i][j] = max({a,b});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i = n-1; i>=0;i--){
            for(int j = m-1; j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j] =  1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        
    }
};