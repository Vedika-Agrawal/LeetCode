class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int idx,int prev){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][prev +1]!=-1){
            return dp[idx][prev+1];
        }
        int not_take=solve(nums,idx+1,prev);
        int take=0;
        if(prev==-1 || nums[idx] > nums[prev]){
            take=1+solve(nums,idx+1,idx);
        }
        return dp[idx][prev+1]=max(take,not_take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(nums,0,-1);
    }
};