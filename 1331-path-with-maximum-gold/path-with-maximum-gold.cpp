class Solution {
public:
    int n;
    int m;
    vector<int>dir={-1, 0, 1, 0 ,-1};

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0 || vis[r][c]==1)return 0;
        vis[r][c] = 1;
       
        int a = grid[r][c] + dfs(grid, vis, r-1, c);
        int b = grid[r][c] +dfs(grid, vis, r, c+1);
        int e = grid[r][c] +dfs(grid, vis, r+1, c);
        int d = grid[r][c] + dfs(grid, vis, r, c-1);
        vis[r][c] = 0;
        return max({a,b,e,d});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    vector<vector<int>>vis(n, vector<int>(m,0));
                    int temp = dfs(grid, vis, i , j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};