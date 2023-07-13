class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=1e9,b=1e9,c=1e9;
        if(s[i]==t[j]){
            return dp[i][j] = solve(i+1,j+1,s,t,dp);
        }
        
            a=1+solve(i+1,j+1,s,t,dp);
            b=1+solve(i+1,j,s,t,dp);
            c=1+solve(i,j+1,s,t,dp);
        
        return dp[i][j]=min({a,b,c});
    }
    int minDistance(string s, string t) {
        n=s.size();
        m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
    }
};