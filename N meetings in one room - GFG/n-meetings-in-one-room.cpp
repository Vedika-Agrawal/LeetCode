//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,int>&p, pair<int,int>&q){
        if(p.first==q.first){
            return p.second<q.second;
        }
        
            return p.first<q.first;
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>pp;
        for(int i=0;i<n;i++){
            pp.push_back({start[i], end[i]});
        }
        sort(pp.begin(),pp.end(), compare);
        int cnt  = 0;
        int a= INT_MIN, b = INT_MIN;
        for(auto it: pp){
            if(it.first>b){
                cnt++;
                a= it.first, b = it.second;
            }
            else{
                if(it.second<b){
                    a= it.first;
                    b = it.second;
                }
            }
        }
        return cnt;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends