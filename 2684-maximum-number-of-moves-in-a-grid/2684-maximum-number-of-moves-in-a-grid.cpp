class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
    int ans = 0;
    vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), 0));
    for(int c = grid[0].size()-2; c >= 0; --c){
        for(int r = 0; r < grid.size(); ++r ){
            if(r - 1 >= 0 && grid[r][c] < grid[r-1][c+1])  { 
                dp[r][c] = max(dp[r][c], 1 + dp[r-1][c+1]); 
            }
            if( grid[r][c] < grid[r][c+1]) { 
                dp[r][c] = max(dp[r][c], 1 + dp[r][c+1]); 
            }
            if(r + 1 < grid.size() && grid[r][c] < grid[r+1][c+1]) { 
                dp[r][c] = max(dp[r][c], 1 + dp[r+1][c+1]); 
            }
            if(c == 0) { ans = max(ans, dp[r][c]);  }
        }
    }
    return ans;
}
};