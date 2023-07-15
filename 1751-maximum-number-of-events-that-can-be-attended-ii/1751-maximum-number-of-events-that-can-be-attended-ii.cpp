
class Solution {
public:
    int n;
    typedef vector<int> p;
    int solve(vector<vector<int>>&nums, int k, int idx, int prev, vector<p>&dp){
        if(idx==n || k==0)return 0;
        if(dp[k][prev+1]!=-1)return dp[k][prev+1];
        int consider = 0;
        int notConsider = solve(nums, k, idx+1, prev,dp);
        if(prev==-1){
            int val = nums[idx][2];
            
            consider = val + solve(nums, k-1 ,idx+1, idx,dp);
        }
        else{
            int pst = nums[prev][0];
            int pend = nums[prev][1];
            int pval = nums[prev][2];
            
            int cst = nums[idx][0];
            int cend = nums[idx][1];
            int cval = nums[idx][2];
            
            if(pend < cst){
                consider =  cval + solve(nums, k-1, idx+1, idx,dp);
            }
            
        }
        return  dp[k][prev+1]= max(consider, notConsider);
        
        
    }
    int maxValue(vector<vector<int>>& nums, int k) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vector<p>dp(k+1, p(n+1, -1));
        return solve(nums, k,0, -1,dp);
    }
};