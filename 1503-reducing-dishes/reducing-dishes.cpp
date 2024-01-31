class Solution {
public:
    // int solve(vector<int>&satisfaction, int currIdx, int noOfDishes,  vector<vector<int>>&dp){
    //     if(currIdx>=satisfaction.size()) return 0;
    //     if(dp[currIdx][noOfDishes]!=-1) return dp[currIdx][noOfDishes];
    //     int take = (noOfDishes * satisfaction[currIdx] ) + solve(satisfaction, currIdx+1, noOfDishes+1,dp);
    //     int notTake = solve(satisfaction, currIdx+1, noOfDishes,dp);
    //     return dp[currIdx][noOfDishes] = max(take, notTake);
    // }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        sort(satisfaction.begin(),satisfaction.end());

        for(int idx =  n-1; idx>=0;idx--){
            for(int noOfDishes = 1; noOfDishes<=n; noOfDishes++){
                int take = (noOfDishes * satisfaction[idx])  + dp[idx+1][noOfDishes+1];
                int notTake = dp[idx+1][noOfDishes];
                dp[idx][noOfDishes] = max(take, notTake);
            }
        }
        return dp[0][1];
    }
};