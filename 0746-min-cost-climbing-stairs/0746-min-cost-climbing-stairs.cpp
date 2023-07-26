class Solution {
public:
    int n ;
    vector<int>dp;
    int solve(vector<int>&cost, int idx){
        if(idx>=n)return 0;
        if(dp[idx+1]!=-1){
            return dp[idx+1];
        }
        int one  = 0, two = 0 ;
        if(idx+1<n)
        one = cost[idx+1] + solve(cost, idx+1);
        if(idx+2<n)
        two = cost[idx+2] + solve(cost, idx+2);
        return dp[idx+1] =min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
       n = cost.size();
        dp.resize(n+1, -1);
        return solve(cost, -1);
    }
};