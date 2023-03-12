class Solution {
public:
    
    void bfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j]==1 || grid[i][j]=='0')return ;
        // vis[i][j]=1;
        // bfs(grid,vis,--i,j);
        // bfs(grid,vis,++i,j);
        // bfs(grid,vis,i,--j);
        // // bfs(grid,vis,i,++j);
        
        vis[i][j] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            bfs(grid, vis, ni, nj);
        }

        
       
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};