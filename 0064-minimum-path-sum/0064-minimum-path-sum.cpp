class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return INT_MAX;
        if(vis[i][j]!=-1)return vis[i][j];
        
        int l = solve(i-1, j, grid, vis);
        int m = solve(i,j-1,grid,vis);
       return vis[i][j] =   grid[i][j] + min(l,m) ; 
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        return  solve(n-1,m-1,grid,vis);
    
    }
};