class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums, int i,int prev){
        if(i>=nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take = 0, notTake =0;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1 + solve(nums, i+1, i);
        }
        notTake = solve(nums, i+1,prev);
        return dp[i][prev+1] = max(take,notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums, 0, -1);
    }
};