class Solution {
public:
    int solve(vector<int>&jd, int d, int idx, vector<vector<int>>&dp){
        if(d==1){
            int mx = jd[idx];
            for(int i= idx; i<jd.size(); i++){
                mx = max(mx, jd[i]);
            }
            return mx;
        }
        if(dp[idx][d]!=-1)return dp[idx][d];
        int ans = 1e9;
        int mx = INT_MIN;
        for(int i = idx; i<jd.size()-d+1; i++){
            mx = max(mx, jd[i]);
            int temp = mx + solve(jd, d-1, i+1,dp);
            ans = min(ans, temp);
        }
        return dp[idx][d]=  ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        if(d>n)return -1;
        return solve(jobDifficulty, d, 0, dp);
    }
};

 