class Solution {
public:
   
    vector<vector<int>>dp;
    int solve(vector<int>&nums, int i, int prev){
        if(i>=nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int deletee = 1 + solve(nums, i+1, prev);
        int notDelete = INT_MAX;
        if(prev==-1 || nums[i]>=nums[prev]){
            notDelete = solve(nums, i+1, i);
        }
        return dp[i][prev+1] = min(notDelete, deletee);
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(nums, 0,-1);
    }
};