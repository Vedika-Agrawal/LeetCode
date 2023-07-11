class Solution {
public:
    int solve(int amt, vector<int>&arr, int idx, vector<vector<int>>&dp){
        if(idx==0){
            return amt%arr[idx]==0 ;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int notTake =  solve(amt, arr, idx-1,dp);
        int take = 0;
        if(arr[idx]<=amt){
            take = solve(amt-arr[idx], arr, idx,dp);
        }
        return dp[idx][amt] = take+ notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return solve(amount, coins, n-1,dp);
    }
};