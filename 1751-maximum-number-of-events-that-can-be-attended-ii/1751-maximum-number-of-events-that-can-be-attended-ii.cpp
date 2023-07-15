class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int search(vector<vector<int>>&nums, int val){
        int l = 0, h =  nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid][0] > val){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    
    int solve(vector<vector<int>>&nums, int k, int idx){
        if(idx==n || k==0)return 0;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int next = search(nums, nums[idx][1]);
        
        int take = 0, nontake =0 ;
        take = nums[idx][2] + solve(nums, k-1, next);
        nontake =solve(nums, k, idx+1);
        return  dp[idx][k] = max(nontake, take);
        
    }
    
    int maxValue(vector<vector<int>>& nums, int k) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.resize(n+1, vector<int>(k+1, -1));
        return solve(nums, k, 0);
    }
};