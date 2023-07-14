typedef  vector<int> p;
class Solution {
public:
    int n;
    int solve(vector<int>&v, int idx, int cnt, int buy, vector< vector<p>>&dp){
        if(idx==n || cnt==2)return 0;
        if(dp[idx][buy][cnt] !=-1)return dp[idx][buy][cnt];
        int profit = 0;
        if(buy){
            profit  = max( -v[idx] + solve(v, idx+1, cnt, 0, dp), solve(v,idx+1,cnt,1, dp));
        }
        else{
             profit  = max( v[idx] + solve(v, idx+1, cnt+1, 1, dp), solve(v,idx+1,cnt,0, dp));
        }
        return dp[idx][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& v) {
        n = v.size();
        vector< vector<p>>dp(n, vector<p>(2, p(2,-1)));
        return solve(v,0,0, 1,dp);
    }
};