class Solution {
public:
    int solve(vector<int>&satisfaction, int currIdx, int noOfDishes,  vector<vector<int>>&dp){
        if(currIdx>=satisfaction.size()) return 0;
        if(dp[currIdx][noOfDishes]!=-1) return dp[currIdx][noOfDishes];
        int take = (noOfDishes * satisfaction[currIdx] ) + solve(satisfaction, currIdx+1, noOfDishes+1,dp);
        int notTake = solve(satisfaction, currIdx+1, noOfDishes,dp);
        return dp[currIdx][noOfDishes] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction, 0, 1, dp);
    }
};