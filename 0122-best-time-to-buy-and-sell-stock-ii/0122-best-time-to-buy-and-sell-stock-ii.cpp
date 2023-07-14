class Solution {
public:
   // long solve(vector<int>&values, int n, int idx, int buy,vector<vector<long>>&dp){
   //      if(idx==n)return 0;
   //      if(dp[idx][buy]!=-1)return dp[idx][buy];
   //      int profit = 0 ;
   //      if(buy){
   //          profit = max(-values[idx] + solve(values, n, idx+1, 0,dp) ,  solve(values,  n, idx+1, 1, dp));
   //      }
   //      else{
   //           profit = max( (values[idx] + solve(values, n, idx+1,1, dp)) ,  solve(values,  n, idx+1, 0,dp));
   //      }
   //      return dp[idx][buy] =profit;
   //  }
    
    int maxProfit(vector<int>& values) {
        
        int n = values.size();
        vector<vector<long>>dp(n+1, vector<long>(2,-1));
        dp[n][0] = dp[n][1] = 0;
        int profit ;
        for(int idx= n-1;idx>=0;idx--){
            for(int buy=0; buy<=1;buy++){
                
                if(buy){
                    profit = max(values[idx] + dp[idx+1][ 0] ,  dp[idx+1][ 1]); 
                }
                else{
                     profit = max( (-values[idx] + dp[idx+1][ 1]) , dp[idx+1][ 0] );
                }
                dp[idx][buy] =profit;
            }
        }
        return dp[0][0];
    }
};
