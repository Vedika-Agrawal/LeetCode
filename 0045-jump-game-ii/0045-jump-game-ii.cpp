class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        fill(dp.begin(),dp.end(),-1);
        dp[n-1]=0;
        for(int i= n-2;i>=0;i--){
            int mini = INT_MAX;
            int step = nums[i];
            for(int j=1;j<=step && i+j<n;j++){
                if(dp[i+j]!=-1 && dp[i+j]<mini)
                mini =  dp[i+j];
            }
            if(mini != INT_MAX){
                dp[i]=mini+1;
                
            }
           
        }
        return dp[0];
    }
};