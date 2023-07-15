//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int i, int j, int arr[],vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1e9;
        for(int k=i;k<j;k++){
            int temp = arr[i-1] * arr[k] * arr[j] + solve(k+1,j,arr,dp) + solve(i,k,arr,dp);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        return solve(1,n-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends