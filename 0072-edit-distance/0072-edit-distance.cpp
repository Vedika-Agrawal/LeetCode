class Solution {
public:
    int n,m;
    int solve(string &s, string &t, int i, int j,vector<vector<int>>&dp){
        
        if(i==n ){
            return m-j;
        }
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        int same = 1e9;
        if(s[i]==t[j]){
            
            return solve(s,t,i+1,j+1,dp);
        }
        
        int insert = 1e9, del = 1e9, rep = 1e9;
        
        insert = 1 + solve(s,t,i,j+1,dp);
        del = 1 + solve(s,t,i+1,j,dp);
        rep = 1+ solve(s,t,i+1, j+1,dp);
        return dp[i][j] = min({insert, del, rep}) ;
    }
    int minDistance(string s, string t) {
        
        n = s.size(), m= t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1, -1));
        return solve(s,t,0,0,dp);
    }
};