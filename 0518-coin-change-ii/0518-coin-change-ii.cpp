class Solution {
public:
    // int solve(int amt, vector<int>&arr, int idx, vector<vector<int>>&dp){
    //     if(idx==0){
    //         return amt%arr[idx]==0 ;
    //     }
    //     if(dp[idx][amt]!=-1)return dp[idx][amt];
    //     int notTake =  solve(amt, arr, idx-1,dp);
    //     int take = 0;
    //     if(arr[idx]<=amt){
    //         take = solve(amt-arr[idx], arr, idx,dp);
    //     }
    //     return dp[idx][amt] = take+ notTake;
    // }
    
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int i= 0; i<=amount; i++){
            if(i%arr[0]==0){
                dp[0][i] = 1;
            }
        }
        
        for(int idx=1;idx<n;idx++){
            for(int amt = 0; amt<= amount; amt++){
                int notTake =  dp[idx-1][amt] ;
                int take = 0;
                if(arr[idx]<=amt){
                    take = dp[idx][amt-arr[idx]];
                }
                dp[idx][amt] = take+ notTake;
            }
        }
        return dp[n-1][amount];
    }
};