class Solution {
public:
    int n, m;
    int solve(string &s1, string &s2, int idx1, int idx2,vector<vector<int>>&dp){
        if(idx1>=n || idx2>=m)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2] =  1 + solve(s1,s2,idx1+1, idx2+1,dp);
        else return dp[idx1][idx2] = max( solve(s1,s2,idx1+1, idx2,dp), solve(s1,s2,idx1, idx2+1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
       n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};