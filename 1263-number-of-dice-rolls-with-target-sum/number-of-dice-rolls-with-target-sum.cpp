class Solution {
public:
    int mod = 1e9+7;
    int n, k, tar;
    int dp[31][1001];
    int helper(int dice, int sum){
        if(dice>n || sum>tar)return 0;
        if(dice==n && sum==tar)return 1;
        if(dp[dice][sum]!=-1)return dp[dice][sum];
        int ans = 0;
        for(int i = 1; i<=k;i++){
           ans = (ans + helper(dice+1, sum+i)%mod)%mod;
        }
        return dp[dice][sum] = ans%mod;
    }
    int numRollsToTarget(int N, int K, int T) {
        n= N, k= K , tar = T;
        memset(dp, -1, sizeof(dp));
        return helper(0,0);
    }
};