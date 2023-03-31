class Solution {
public:
    long long MOD = 1000000007;
    bool hasApple(vector<string>& grid, int startRow,int startCol, int endRow, int endCol){
        for(int i=startRow; i<=endRow;i++){
            for(int j=startCol; j<=endCol; j++){
                if(grid[i][j]=='A')return true;
            }
        }
        return false;
    }
    
    int solve(vector<string>& grid, int sr, int sc, int k,vector<vector<vector<int>>>& dp){
        int n = grid.size(), m= grid[0].size();
        if(k==0)return 1;
        if(dp[sr][sc][k]!=-1)return dp[sr][sc][k];
        
        long long ans =0;
        
        for(int i= sr; i<n-1; i++){
            bool uApple = hasApple(grid,sr,sc,i,m-1);
            bool lApple = hasApple(grid,i+1,sc,n-1,m-1);
            
            if(uApple && lApple){
                int ways = solve(grid, i+1, sc, k-1,dp );
                ans = (ans + ways)%MOD;
            }
        }
        
         for(int i= sc; i<m-1; i++){
            bool uApple = hasApple(grid,sr,sc,n-1,i);
            bool lApple = hasApple(grid,sr,i+1,n-1,m-1);
            
            if(uApple && lApple){
                int ways = solve(grid, sr, i+1, k-1,dp );
                ans = (ans + ways)%MOD;
            }
        }
        return dp[sr][sc][k] = int(ans);
    } 
    
    int ways(vector<string>& pizza, int k) {
        int n= pizza.size(),m=pizza[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(pizza, 0,0, k-1,dp);
    }
};