//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  #define lli long long
  #define ll long long
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    lli mergeTwo(ll st, ll end, ll mid, ll arr[]){
        vector<ll>temp;
        ll l=st, r = mid+1;
        ll cnt = 0;
        
        while(l<=mid && r<=end){
            if(arr[l]>arr[r]){
                cnt += mid- l+1;
                temp.push_back(arr[r]);
                r++;
            }
            else{
                temp.push_back(arr[l]);
                l++;
            }
        }
        
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
         while(r<=end){
            temp.push_back(arr[r]);
            r++;
        }
        int k =0 ;
        for(ll i = st; i<=end; i++){
            arr[i] = temp[k];
            k++;
        }
        return cnt;
        
        
    }


    lli mergesort(ll st, ll end, ll arr[]){
        lli cnt= 0;
        if(st<end){
            ll mid = (st+end)/2;
            cnt += mergesort(st, mid, arr);
            cnt += mergesort(mid+1,end, arr);
            cnt += mergeTwo(st,end,mid,arr);
        }
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(0, N-1, arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends