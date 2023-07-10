class Solution {
public:
    int n , m;
    
//     int solve(vector<vector<int>> &grid, int r , int c){
//         if(r==n-1 && c==m-1){
//             return  grid[r][c];
//         }
//         if(r>=n || c>=m){
//             return INT_MAX;
//         }
//         if(dp[r][c]!=-1)return dp[r][c];

//         int right = INT_MAX, down= INT_MAX;
//         if(c+1<m)
//         right = solve(grid,r,c+1) + grid[r][c];
//         if(r+1<n)
//         down = solve(grid,r+1,c) + grid[r][c];
//         return dp[r][c] = min(right,down);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
     
        
        for(int i = n-1; i>=0;i--){
            for(int j=m-1; j>=0;j--){
                if(i==n-1 && j==m-1) {
                    dp[n-1][m-1] = grid[n-1][m-1];
                    continue;
                }
                else if(i==n-1){
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                else if(j==m-1){
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
                }
            }
        }
        return dp[0][0];
                 
    }
};