class Solution {
public:
    

    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&nums, int st, int end){
        if(st>end)return 0;
        if(dp[st][end]!=-1)return dp[st][end];
        int ans = 0;
        for(int i= st; i<=end; i++){
            int pp = nums[st-1];
            int nn = nums[end+1];
            int a = (pp * nums[i] * nn) + solve( nums, st, i-1) + solve(nums, i+1, end);
            ans = max(ans, a);
            
        }
        return dp[st][end]= ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+2, vector<int>(n+2,-1));
        nums.push_back(1);
        nums.insert(begin(nums),1);
        return solve(nums, 1, n);
    }
};