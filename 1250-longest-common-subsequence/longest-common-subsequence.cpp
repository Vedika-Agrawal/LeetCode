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
        // int c = solve(s, t, i+1,j+1,dp);
        return dp[i][j] = max({a,b});
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(),-1));
        return solve(text1, text2, 0 ,0,dp);
    }
};