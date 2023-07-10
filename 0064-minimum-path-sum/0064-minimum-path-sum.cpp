class Solution {
public:
    int n , m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>> &grid, int r , int c){
        if(r==n-1 && c==m-1){
            return  grid[r][c];
        }
        if(r>=n || c>=m){
            return INT_MAX;
        }
        if(dp[r][c]!=-1)return dp[r][c];

        int right = INT_MAX, down= INT_MAX;
        if(c+1<m)
        right = solve(grid,r,c+1) + grid[r][c];
        if(r+1<n)
        down = solve(grid,r+1,c) + grid[r][c];
        return dp[r][c] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(grid, 0,0);
                 
    }
};