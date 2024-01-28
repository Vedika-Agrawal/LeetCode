class Solution {
public:
#define ll long long
    

    int minFallingPathSum(vector<vector<int>>& mat) {
    
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = mat[n - 1][i];
        }

        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
               ll b = 1ll * mat[r][c] + dp[r + 1][c];
                ll a = 1ll * mat[r][c] + (c + 1 < m ? dp[r + 1][c + 1] : 1e5);
                ll d = 1ll * mat[r][c] + (c - 1 >= 0 ? dp[r + 1][c - 1] : 1e5);
                dp[r][c] = min({a, b, d});
            }
        }
        int ans = 1e9;
        for(int c =0;c<m;c++){
            ans = min(ans, dp[0][c]);
        }
        return ans;
    }
};