//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
 
    int longestSubsequence(int n, int a[])
    {
        vector<int>temp;
        for(int i=0;i<n;i++){
            int curr_ele = a[i];
            int idx = lower_bound(temp.begin(),temp.end(),curr_ele)-temp.begin();
            if(idx!=temp.size()){
                temp[idx] = curr_ele;
            }
            else temp.push_back(curr_ele);
        }
        return temp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } 