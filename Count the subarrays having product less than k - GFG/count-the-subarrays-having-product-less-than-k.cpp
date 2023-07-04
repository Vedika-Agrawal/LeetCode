//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0;
        int cnt  =0 ;
        long long curr_pro =1;
        while(j<n){
            curr_pro *= a[j];
           
            while(i<j && curr_pro>=k ){
                curr_pro/=a[i];
                i++;
            }
            if(curr_pro<k){
                cnt+=(j-i+1);
               
            }
            j++;
            
        }
       
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends