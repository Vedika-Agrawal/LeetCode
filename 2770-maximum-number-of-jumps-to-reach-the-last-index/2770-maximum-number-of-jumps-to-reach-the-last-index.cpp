class Solution {
public:
   vector<int>dp;
    int maximumJumps(vector<int>& nums, int tar) {
        int n = nums.size();
        dp.resize(n+1,-1);
        dp[0]=0;
        for(int i= 1; i<n;i++){
            for(int j = i-1;j>=0;j--){
                int temp = abs(nums[i]-nums[j]);
                if(temp<=tar && dp[j]>-1){
                    dp[i] = dp[i] = max(dp[i], dp[j]+1);
                }
                
            }
        }
        return dp[n-1];
    }
    
};
//     int solve(vector<int>&nums, int tar,int n){
//         if(n==0)return 0;
//         if(dp[n]!=-1)return dp[n];
//          int ans = INT_MIN;
//         for(int i = n-1; i>=0;i--){
        
//             int temp = abs(nums[n] - nums[i]);
//             if(temp<=tar){
//                 ans = max(ans, solve(nums,tar, i)+1);
//                 dp[n] = ans;
//             }

//         }
//         return ans;
        
