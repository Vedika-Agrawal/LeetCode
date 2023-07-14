class Solution {
public:
   long solve(vector<int>&values, int n, int idx, int buy,vector<vector<long>>&dp){
        if(idx==n)return 0;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit = 0 ;
        if(buy){
            profit = max(-values[idx] + solve(values, n, idx+1, 0,dp) ,  solve(values,  n, idx+1, 1, dp));
        }
        else{
             profit = max( (values[idx] + solve(values, n, idx+1,1, dp)) ,  solve(values,  n, idx+1, 0,dp));
        }
        return dp[idx][buy] =profit;
    }
    
    int maxProfit(vector<int>& p) {
        
        int n = p.size();
         vector<vector<long>>dp(n, vector<long>(2,-1));
        return solve(p, n, 0,1,dp);
    }
};