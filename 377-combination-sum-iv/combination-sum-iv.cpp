class Solution {
public:
   vector<int>dp;
    int solve(vector<int>&num, int tar){
        if(tar<0)return 0;
        if(tar==0)return 1;
        int ans=0 ;
        if(dp[tar]!=-1)return dp[tar];
        for(int i=0;i<num.size();i++){
            ans += solve(num, tar-num[i]);
        }
        return dp[tar] = ans;
    }
    int combinationSum4(vector<int>& num , int tar) {
        dp.resize(tar+1, -1);
        return solve(num, tar);
    }
};