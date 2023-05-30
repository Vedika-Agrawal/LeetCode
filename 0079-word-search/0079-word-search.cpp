class Solution {
public:
    int n,m;
    
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, string word, int idx, int r, int c){
        if(idx==word.size())return true;
        if(r<0 || c<0 || r>=n || c>=m  || vis[r][c])return false;
        if(idx>=word.size())return false;
        if(word[idx]!=grid[r][c])return false;
       
                 // cout<<r<<" "<<c<<endl;

        vis[r][c]=1;
        int a = dfs(grid,vis,word,idx+1,r-1,c) ;
        int b = dfs(grid,vis,word,idx+1,r,c+1);
        int e = dfs(grid,vis,word,idx+1,r+1,c);
        int d = dfs(grid,vis,word,idx+1,r,c-1);
        if(a||b||e||d)return true;
        vis[r][c]=0;
        
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
       n = board.size(), m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==word[0] ){
                    
                    if(dfs(board,vis,word, 0, i,j))
                    {
                        return true;
                        cout<<i<<" "<<j<<endl;
                    }
                       
                }
            }
        }
        return false;
    }
};



int n,m;
    
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, string word, int idx, int r, int c){
        if(idx==word.size())return true;
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c])return false;
        if(idx>=word.size())return false;
        if(word[idx]!=grid[r][c])return false;
        
                 // cout<<r<<" "<<c<<endl;

        vis[r][c]=1;
        int a = dfs(grid,vis,word,idx+1,r-1,c) ;
        int b = dfs(grid,vis,word,idx+1,r,c+1);
        int e = dfs(grid,vis,word,idx+1,r+1,c);
        int d = dfs(grid,vis,word,idx+1,r,c-1);
        if(a||b||e||d)return true;
        vis[r][c]=0;
        
        
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
       n = board.size(), m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==word[0] ){
                    
                    if(dfs(board,vis,word, 0, i,j))
                    {
                        return true;
                        cout<<i<<" "<<j<<endl;
                    }
                       
                }
            }
        }
        return false;
    }