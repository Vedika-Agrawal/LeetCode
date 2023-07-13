class Solution {
public:
    int mod = 1e9+7;
    int numDistinct(string s, string t) {
         long long n = s.size(), m = t.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<vector<long long>>dp(m+1, vector<long long>(n+1, 0));
        for(int col = 0; col<=n;col++){
            dp[0][col]=1;
        }
        for(int row = 1; row<=m; row++){
            for(int col=1; col<=n; col++){
                dp[row][col] = (dp[row][col-1])%mod;
                if(row==1){
                    if(s[col-1] == t[row-1]){
                        dp[row][col] ++;
                    }
                  
                }
                
                else if(s[col-1]==t[row-1]){
                    dp[row][col] += (dp[row-1][col-1])%mod;
                    
                }
            }
        }
        return dp[m][n];
    }
};