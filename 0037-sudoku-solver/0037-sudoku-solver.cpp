class Solution {
public:
    
    bool isSafe(int r, int c, vector<vector<char>>& board, char ch){
        
        for(int i= 0; i<9; i++){
            if(board[i][c]==ch)return false;
            if(board[r][i]==ch)return false;
            
           
        }
        int rst = (r/3)*3;
            int cst = (c/3)*3;
         for( int k = rst; k<rst+3; k++ ){
                for(int l = cst; l<cst+3; l++){
                    if(board[k][l]==ch)return false;
                }
         }
            
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.'){
                    for(char ch = '1'; ch<='9'; ch++){
                        if(isSafe(i,j,board, ch)){
                            board[i][j] = ch;
                            if(solve(board))return true;
                            else
                             board[i][j]='.' ;
                                
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return ;
    }
};