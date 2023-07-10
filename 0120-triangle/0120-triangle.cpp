class Solution {
public:
    int n;
    
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&grid, int i, int j){
        if(dp[i][j]!=-1)return dp[i][j];
  
        if(i==n-1){
            return grid[i][j];
        }
       // if(dp[i][j]==-1)return dp[i][j];
        int temp1 = grid[i][j] + solve(grid, i+1, j);
        int temp2 = grid[i][j] + solve(grid, i+1, j+1);
        
        return dp[i][j] = min(temp1,temp2);
        
    }
    
    int minimumTotal(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(grid, 0, 0);
    }
};