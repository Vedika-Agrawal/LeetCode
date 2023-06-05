class Solution {
public:
    vector<int>possible = {1,2,3,4,5,6,7,8,9};
    
    bool isPossible( int row, int col, vector < vector < char >> & board, char c) {
      for (int i = 0; i < 9; i++) {
        if (board[i][col] == c)
          return false;

        if (board[row][i] == c)
          return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
          return false;
      }
      return true;
    }

  

    bool solve(vector<vector<char>>& board){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        char ch = k +'0';
                        if(isPossible(i,j,board,ch)) {
                            board[i][j]=ch;
                             if(solve(board))return true;
                             else
                             board[i][j] = '.';
                        }
                       
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
//     bool solve(vector < vector < char >> & board) {
//       for (int i = 0; i < board.size(); i++) {
//         for (int j = 0; j < board[0].size(); j++) {
//           if (board[i][j] == '.') {
//             for (int c = 1; c <= 9; c++) {
//               if (isPossible( i, j,board, c)) {
//                 board[i][j] = c;

//                 if (solve(board))
//                   return true;
//                 else
//                   board[i][j] = '.';
//               }
//             }

//             return false;
//           }
//         }
//       }
//       return true;
//     }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
        return ;
    }
};