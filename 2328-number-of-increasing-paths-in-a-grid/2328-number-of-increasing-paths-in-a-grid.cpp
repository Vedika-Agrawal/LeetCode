#define ll long long
class Solution {
public:
    int n, m;
    int mod = 1e9+7;
    vector<vector<int>>dp;
    vector<int>dir= {-1,0,1,0,-1};
    int dfs(vector<vector<int>>&grid, int r, int c){
        ll ans  = 1;
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        for(int k=0;k<4;k++){
            int nr = r+ dir[k];
            int nc =  c + dir[k+1];
            if( nr>=0 && nc>=0 && nr<n && nc<m && grid[r][c] < grid[nr][nc] ){
                ans += (dfs(grid, nr,nc))%mod;
            }
        }
        return dp[r][c] = ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans  =0;
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // ans += (dfs(grid, i,j))%mod;
                ans = (ans +  (dfs(grid,i,j)%mod))%mod;
            }
        }
        return (int)ans%mod;
    }
};