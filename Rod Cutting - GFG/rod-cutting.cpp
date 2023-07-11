//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int length = 0;
    int solve(int arr[], int idx, int n, vector<vector<int>>&dp){
        if(idx==length || n==0){
            return 0;
        }
        if(dp[idx][n]!=-1)return dp[idx][n];
        int notTake = solve(arr, idx+1, n,dp);
        int take = 0;
        int len = idx+1;
        if(len<= n){
            take = arr[idx] + solve(arr, idx, n - len,dp); 
        }
        return dp[idx][n] =  max(take , notTake);
        
    }
    int cutRod(int arr[], int N) {
        length = N;
        vector<vector<int>>dp(N+1, vector<int>(N+1,0));
        for(int idx = N-1; idx>=0; idx--){
            for(int n =0 ; n<= N; n++){
                
                int notTake = dp[idx+1][n]; 
                int take = 0;
                int len = idx+1;
                if(len<= n){
                    take = arr[idx] + dp[idx][ n - len]; 
                }
                dp[idx][n] =  max(take , notTake);
                
             }
        }
        return dp[0][N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends