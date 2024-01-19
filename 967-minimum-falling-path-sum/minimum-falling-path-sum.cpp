class Solution {
public:
    #define ll long long
    int n, m;
    vector<vector<int>>dp;
    ll solve(int r, int c, vector<vector<int>>&mat){
        if(r<0 || c<0 || r>=n || c>=m)return 1e9;
        if(r==n-1)return mat[r][c];
        if(dp[r][c]!=1e9+1)return dp[r][c];
        ll a = (ll)mat[r][c] + solve(r+1,c-1,mat);
        ll b = (ll)mat[r][c] + solve(r+1,c,mat);
        ll d = (ll) mat[r][c] + solve(r+1,c+1,mat);
        return dp[r][c] = min({a,b,d});

    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans = INT_MAX;
         n = mat.size();
         m = mat[0].size();
         dp.resize(n,vector<int>(m,1e9+1));
        for(int i=0;i<m;i++){
            int temp_ans = solve(0,i, mat);
            ans = min(ans, temp_ans);
        }
        return ans;
    }
};