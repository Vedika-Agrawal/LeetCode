class Solution {
public:
    int n,m;
    vector<vector<int>>vis;
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int k){
         if(k==word.size())return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k] || vis[i][j]==1)return false;
       
        vis[i][j] =1;
        int a  = dfs(board, i-1, j, word, k+1);
        int b  =  dfs(board, i, j+1, word, k+1);
        int c  = dfs(board, i+1, j, word, k+1) ;
        int d  = dfs(board, i, j-1, word, k+1);
        if(a||b||c||d)return true;
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vis.resize(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(board, i, j, word, 0) ){
                    return true;
                }
            }
        }
        return false;
    }
};