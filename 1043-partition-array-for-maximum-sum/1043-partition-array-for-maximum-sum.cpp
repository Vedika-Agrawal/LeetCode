class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>&arr, int k, int idx){
        if(idx==n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans = INT_MIN;
        int mx  = INT_MIN;
        int len = 0;
        for(int i = idx; i< min(idx+k, n); i++){
            len++;
            mx = max(mx, arr[i]);
            int tmp_ans = len*mx + solve(arr, k, i+1);
            ans = max(ans, tmp_ans);
        }
        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.resize(n,-1);
        return solve(arr, k, 0 );
    }
};