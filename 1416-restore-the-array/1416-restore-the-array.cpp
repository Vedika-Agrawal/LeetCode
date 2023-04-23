class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(), -1);
        return solve(s,k,0,dp);
    }
    
    int solve(string &s, int k ,int i, vector<int>&dp){
        if(i==s.size())return 1;
        if(s[i]=='0') return 0 ;
        if (dp[i] != -1) return dp[i];
        int ans = 0 ;
        long nums = 0;
        for(int j = i; j<s.size();j++){
            nums = nums * 10  +  s[j]-'0';
            if(nums>k)break;
            ans = (ans + solve(s,k,j+1,dp)%MOD)%MOD;
        }
        return dp[i]=ans;
    }
};