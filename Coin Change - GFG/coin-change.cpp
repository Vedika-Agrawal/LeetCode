//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  typedef long long int ll;
  vector<vector<ll>>dp;
  ll solve(int coins[],int i,int sum){
      if(i==0){
          return sum%coins[i]==0;
      }
      if(dp[sum][i]!=-1)return dp[sum][i];
      ll total=0;
      total+=solve(coins,i-1,sum);
      if(sum>=coins[i]){
          total+=solve(coins,i,sum-coins[i]);
      }
      return dp[sum][i]=total;
      
  }
    long long int count(int coins[], int N, int sum) {
        
        // code here.
        dp.resize(sum+1,vector<ll>(N,-1));
        return solve(coins,N-1,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends