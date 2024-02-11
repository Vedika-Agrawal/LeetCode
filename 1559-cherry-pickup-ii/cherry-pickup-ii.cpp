class Solution {
public:
    int n,m;
    int dp[71][71][71];
    bool isValid(int i, int j) {
        return i>=0 && j>=0 && i<n && j<m;
    }
        
    vector<int>dir = { -1, 0, 1};
    int solve(vector<vector<int>>&grid, int r, int c1, int c2){
        if(r==n)return 0;
        int ans = 0;
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        for(int i = 0; i<3; i++){
            for(int j = 0 ;j<3 ; j ++){
                int nc1 = c1 + dir[i];
                int nc2 = c2 + dir[j];
                if(isValid(r+1, nc1) && (isValid(r+1, nc2))){
                    int temp = solve(grid, r+1, nc1, nc2);
                    ans = max(temp, ans);
                }
                
            }
        }
        ans += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};