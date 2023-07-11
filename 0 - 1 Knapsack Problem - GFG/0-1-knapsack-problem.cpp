//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solve(vector<pair<int,int>>&v, int cap, int idx, int point,vector<vector<int>>&dp){
        if(idx==v.size() || cap==0){
            return 0;
        }
        // take
        if(dp[idx][cap]!=-1)return dp[idx][cap];
        int val = v[idx].first;
        int wt = v[idx].second;
        int take = 0, notTake = 0 ;
        if(wt<=cap){
            take = val +  solve(v, cap-wt, idx+1, point+val,dp);
        }
        // not take
        notTake = solve(v, cap, idx+1, point,dp);
        return dp[idx][cap]=max(notTake, take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({val[i], wt[i]});
        sort(v.rbegin(), v.rend());
        vector<vector<int>>dp(n, vector<int>(W+1,-1));
        return solve(v, W, 0, 0,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends