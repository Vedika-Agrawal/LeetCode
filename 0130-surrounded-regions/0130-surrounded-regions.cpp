class Solution {
public:
    
    
    // void dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int i, int j){
    //     vis[i][j]=1;
    //     vector<int>dir = {-1, 0,1,0,-1};
    //     for(int k=0;k<4;k++){
    //         int ni = i + dir[i];
    //         int nj = j + dir[i+1];
    //         if(ni>=0 && nj>=0 && ni<mat.size() && nj<mat[0].size() && !vis[i][j] && mat[i][j]=='O'){
    //             dfs(mat,vis,ni,nj);
    //         }
    //     }
    // }
    
    void dfs(vector<vector<char>> &mat,vector<vector<int>> &vis,int row, int col ){
        vis[row][col] = 1; 
        int n = mat.size();
        int m = mat[0].size();
        vector<int>dir = {-1, 0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow = row + dir[i];
            int ncol = col + dir[i+1];
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs( mat,vis, nrow, ncol); 
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
                       

        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
       
        
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(mat, vis, 0,i);
            }
            
            if(!vis[n-1][i] && mat[n-1][i]=='O'){
                dfs(mat, vis, n-1,i);
            }
            
        }
        
      
         for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(mat, vis, i,0);
            }
            
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(mat, vis, i,m-1);
            }
            
        }
        
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return ;
        
    }
};