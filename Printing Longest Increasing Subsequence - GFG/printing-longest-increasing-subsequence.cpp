//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1),hash(n,0);
        int mx = 0, idx ;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[j]< arr[i] && dp[j]+1> dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>mx){
                mx= dp[i];
                idx= i;
            }
        }
        // cout<<mx;
        vector<int>ans(mx);
        while(idx!= hash[idx]){
            int val = arr[idx];
            ans[mx-1] = val;
            mx--;
            idx = hash[idx];
        }
        ans[0] = arr[idx];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends