class Solution {
public:
    
    int solve(string &a , string &b, int i, int j , vector<vector<int>>&dp){
       if(i==a.size())return b.size()-j;
       if(j==b.size())return a.size()-i;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        if(a[i]==b[j])return solve(a,b,i+1,j+1,dp);
        else{
            int insertAns = 1 + solve(a, b, i, j+1, dp);
            int deleteAns = 1 + solve(a, b, i+1, j, dp);
            int replaceAns = 1 + solve(a, b, i+1, j+1, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));

        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};