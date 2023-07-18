//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int n;
	vector<vector<int>>dp;
	int solve(string &str, int i, int j){
	    if(i==n || j==n)return 0;
	    if(dp[i][j]!=-1)return dp[i][j];
	    int take =0, notTake =0;
	    if(i!=j && str[i]==str[j]){
	        take = 1 + solve(str, i+1, j+1);
	    }
	    else{
	        notTake = solve(str, i+1, j);
	        notTake = max(notTake, solve(str, i, j+1));
	    }
	    return dp[i][j] = max(take, notTake);
	}
		int LongestRepeatingSubsequence(string str){
		    n = str.size();
		    dp.resize(n+1, vector<int>(n+1, 0));
		    for(int i= n-1; i>=0;i--){
		        for(int j= n-1; j>=0; j--){
		            int take =0, notTake =0;
            	    if(i!=j && str[i]==str[j]){
            	        take = 1 + dp[i+1][ j+1];
            	    }
            	    else{
            	        notTake =  dp[i+1][ j];
            	        notTake = max(notTake,  dp[i][ j+1]);
            	    }
            	    dp[i][j] = max(take, notTake);
		        }
		    }
		    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends