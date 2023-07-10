class Solution {
public:
    int n,m;
    
//     int solve(vector<vector<int>>&vis, int r, int c){
        
//         if(r>=n || c>=m )return 0;
        
//         if(r==n-1 && c ==m-1)return 1;
        
//         if( vis[r][c] != -1)return vis[r][c];
        
//         int right = solve(vis,r,c+1);
//         int down = solve(vis,r+1,c);
//         vis[r][c]=0;
        
        
//         return vis[r][c] = right+down;
        
        
//     }
    
    
    int uniquePaths(int r, int c) {
       n= r, m =c ;
        vector<vector<int>>dp(n,vector<int>(m,1));
        
        for(int i = n-2; i>=0; i--){
            for(int j= m-2; j>=0; j--){
                dp[i][j] = dp[i+1][j] +dp[i][j+1];
            }
        }
        return dp[0][0];
        }
};