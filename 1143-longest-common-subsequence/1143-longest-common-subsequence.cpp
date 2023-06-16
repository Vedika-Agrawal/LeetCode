class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(string &s1, string &s2, int i , int j){
        if(i==n || j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
           return dp[i][j]= solve(s1,s2,i+1,j+1) +1;
        }
        else {
            int a  = solve(s1,s2,i+1,j);
            int b  = solve(s1,s2,i,j+1);
           return dp[i][j]=  max(a,b);
        }
        // return dp[n-1][m-1];
    }
    int longestCommonSubsequence(string t1, string t2) {
         n = t1.size(), m = t2.size();
        dp.resize(n,vector<int>(m,-1));
       
         solve(t1,t2,0,0);
        return dp[0][0];
    }
};

