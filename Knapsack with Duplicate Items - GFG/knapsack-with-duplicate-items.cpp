//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n ;
    int solve(int val[], int wt[], int cap, int idx, vector<vector<int>>&dp){
        if(idx==n || cap<=0){
            return 0;
        }
        if(dp[idx][cap]!=-1)return dp[idx][cap];
        int notTake = solve(val, wt, cap, idx+1,dp);
        int take  = 0 ;
        if(wt[idx]<=cap){
            take = val[idx] + solve(val, wt, cap-wt[idx], idx,dp);
        }
        return dp[idx][cap]= max(take, notTake);
    }
    
    int knapSack(int N, int cap, int val[], int wt[])
    {
        n = N;
        vector<vector<int>>dp(n,vector<int>(cap+1,-1));
        return solve(val,wt, cap, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends