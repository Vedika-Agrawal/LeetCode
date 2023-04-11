class Solution {
public:
     void dfs(int i, int j , vector<vector<int>>& vis, vector<vector<int>>& grid ){
        vis[i][j]=1;
        int dir[]={-1,0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr = i + dir[k];
            int nc = j + dir[k+1];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1 ){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    if(i==0 || i==n-1 || j==0 || j==m-1 ){
                        dfs(i,j,vis,grid);
                    }
                   
                }
            }
        }
        
        int cnt =0 ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                    // dfs(i,j,vis,grid);
            
                }
            }
        }
        return cnt;
    }
};