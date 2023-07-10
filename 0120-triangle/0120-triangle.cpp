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
        for(int j=0;j<n;j++){
            dp[n-1][j] = grid[n-1][j];
        }
        for(int i= n-2; i>=0;i--){
            for(int j=0;j<=i; j++){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + grid[i][j];
            }
            
        }
        return dp[0][0];
        
    }
};