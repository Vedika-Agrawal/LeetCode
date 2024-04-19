class Solution {
public:
    int n, m;
    vector<int>dir =  {-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c){
        vis[r][c]=1;
        for(int k = 0; k<4; k++){
            int nr  = r + dir[k];
            int nc  = c + dir[k+1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0){
                dfs(grid, vis, nr, nc);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j= 0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid, vis, i,j);
                        cnt++;
                }
            }
        }
        return cnt;
    }
};