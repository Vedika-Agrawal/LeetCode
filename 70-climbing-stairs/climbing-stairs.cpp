class Solution {
public:
    vector<int>dp;
    int solve(int n, int i){
        if(i>n)return 0;
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int a = solve(n, i+1);
        int b = solve(n, i+2);
        return dp[i] =a+b;
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(n,0);
    }
};