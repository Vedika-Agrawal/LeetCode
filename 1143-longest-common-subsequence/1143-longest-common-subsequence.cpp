class Solution {
public:
    int n, m;
    // int solve(string &s1, string &s2, int idx1, int idx2,vector<vector<int>>&dp){
    //     if(idx1>=n || idx2>=m)return 0;
    //     if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
    //     if(s1[idx1]==s2[idx2]) return dp[idx1][idx2] =  1 + solve(s1,s2,idx1+1, idx2+1,dp);
    //     else return dp[idx1][idx2] = max( solve(s1,s2,idx1+1, idx2,dp), solve(s1,s2,idx1, idx2+1,dp));
    // }
    int longestCommonSubsequence(string &s1, string &s2) {
       n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
       
       for(int idx1 = n-1; idx1>=0; idx1--){
           for(int idx2= m-1;idx2>=0; idx2--){
                if(s1[idx1]==s2[idx2])
                    dp[idx1][idx2] =  1 +  dp[idx1+1][idx2+1]; 
                else 
                  dp[idx1][idx2] = max( dp[idx1+1][idx2], dp[idx1][idx2+1]);
           }
       }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       return dp[0][0]; 
    }
};