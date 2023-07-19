//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int n;
    vector<vector<int>>dp;
    int solve(string s, int i, int j){
        if(i>=n || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take  =0,notTake = 0;
        notTake = solve(s, i+1, j);
        notTake = max(notTake, solve(s, i, j-1));
        
        if(s[i]==s[j]){
            take = 1 + solve(s, i+1, j-1);
        }
        return dp[i][j] = max(take, notTake);
    }
    
    int longestPalinSubseq(string str) {
        n = str.size();
        dp.resize(n+1,vector<int>(n+1, -1) );
        return solve(str, 0, n-1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends