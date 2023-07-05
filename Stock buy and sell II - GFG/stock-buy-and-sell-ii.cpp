//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>>dp;
    int solve(vector<int>&v, int idx, int buy ){
        if(idx==v.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int a=0,b=0;
        if(buy==0){
            // buy
            a = - v[idx] + solve(v, idx+1, 1);
            // not buy
            b = solve(v, idx+1,0);
        }
        else{
            // sell
            a = v[idx] + solve(v, idx+1, 0);
            
            // not sell
            b = solve(v, idx+1, 1);
            
            
        }
        return dp[idx][buy]= max(a,b);
    }
    int stockBuyAndSell(int n, vector<int> &a) {
        dp.resize(n, vector<int>(2, -1));
        return solve(a,0, 0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends