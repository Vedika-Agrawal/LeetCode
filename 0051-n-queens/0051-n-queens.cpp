class Solution {
public:
    vector<vector<string>>ans;
    int n ;
    

    bool isSafe(int r, int c, vector<string>&chess){
        
        for(int i = r, j = c-1; j>=0; j--){
            if(chess[i][j]=='Q')return false;
        }
        
        for(int i = r-1, j = c-1; j>=0 && i>=0; j--, i--){
            if(chess[i][j]=='Q')return false;
        }
        
         for(int i = r+1, j = c-1; j>=0 && i<n; j--, i++){
            if(chess[i][j]=='Q')return false;
        }
        return true;
        
        
    }
    
    
    void solve( int c, vector<string>&chess){
         if(c==n){
            ans.push_back(chess);
            return;
        }
        
        for(int r = 0; r<n;r++){
            if(isSafe(r,c,chess)){
                chess[r][c]='Q';
                solve(c+1,chess);
                chess[r][c]='.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        if(n==2 || n==3)return ans;
        vector<string>chess(n);
        string s (n,'.');
         for(int i=0;i<n;i++){
            chess[i]=s;
        }
        solve(0,chess);
        return ans;
    }
};