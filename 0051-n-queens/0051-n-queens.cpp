class Solution {
public:
    
    vector<vector<string>>ans;
    
    
    bool isSafe(int row, int col , vector<string>board, int n){
        for(int i = row, j = col-1; j >=0 ; j--){
            if(board[i][j]=='Q')return false;
        }
        
        for(int i = row-1, j = col-1; j >=0 && i>=0 ; j--, i--){
            if(board[i][j]=='Q')return false;
        }
        
         for(int i = row-1, j = col-1; j >=0 && i>=0 ; j--, i--){
            if(board[i][j]=='Q')return false;
        }
        
         for(int i = row+1, j = col-1; j >=0 && i<n ; j--, i++){
            if(board[i][j]=='Q')return false;
         }
        return true;
        
    }
    
    void solve(int col, vector<string>&board,int n){ 
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n);
                board[row][col]='.';
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        // if(n==1)return ans.push({"Q"});
        if(n==2 || n==3)return ans;
        vector<string>board(n);
        string s (n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,n);
        return  ans;
    }
};