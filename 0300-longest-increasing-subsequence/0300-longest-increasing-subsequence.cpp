class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&arr, int idx, int prev){
        if(idx==n)return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int notTake = 0, take  = 0;
        notTake = solve(arr, idx+1, prev); 
        if(prev==-1|| arr[idx]> arr[prev]){
            take = 1 + solve(arr, idx+1, idx);
        }
       
        return dp[idx][prev+1] =  max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(nums, 0 , -1);
    }
};