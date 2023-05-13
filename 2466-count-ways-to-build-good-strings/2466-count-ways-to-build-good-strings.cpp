class Solution {
public:
    int l,h,z,o;
    const int mod = 1e9+7;
    
    int solve(int len ,vector<int>&dp ){
        if(len> h)return 0;
        if(dp[len]!=-1)return dp[len];
        int flag = 0;
        if(len>=l && len<=h){
            flag = 1;
        }
        int app_one= solve(len+o,dp)%mod;
        int app_zero = solve(len+z,dp)%mod;
        
        return dp[len] = (app_one + app_zero + flag)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h = high;
        z =zero;
        o = one;
        
        vector<int>dp(high+1,-1);
        return solve(0,dp);
    }
};