class Solution {
public:
    
    int solve(vector<int>&v, int idx, int time, vector<vector<int>>&dp){
        if(idx==v.size())return 0;
        
        if(dp[idx][time]!=-1)return dp[idx][time];
        
        int incl = v[idx]* (time +1) + solve(v,idx+1,time+1,dp);
        int excl = solve(v,idx+1,time,dp);
        
        dp[idx][time]= max(incl,excl);
        
        return max(incl,excl);
    }
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(v,0,0,dp);
    }
};