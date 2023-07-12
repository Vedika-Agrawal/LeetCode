//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    int p = 1e9+7;
    long long poww(long long x, unsigned int y, int p)
    {
        int res = 1;     // Initialize result
     
        x = x % p; // Update x if it is more than or
                    // equal to p
      
        if (x == 0) return 0; // In case x is divisible by p;
     
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;
     
            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
    
    long long power(int N,int R)
    {
       return poww(N,R,p);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends