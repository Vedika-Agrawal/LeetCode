//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n){
        int ans = 0;
        while(n>9){
            int ans = 0;
          while(n>0){
              int rem = n%10;
              n/=10;
              ans += (rem*rem);
          } 
          n = ans;
        }
        if(n==1 || n==7)return true;
        return false;
    }
    int nextHappy(int N){
        while(isHappy(N+1)==false){
            N++;
        }
        return N+1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends