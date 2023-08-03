//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>vis(N,0);
        vector<int>dis(N,1e9);
        
        queue<pair<int,int>>q;
        dis[0]=0;
        q.push({0,0});
        
        while(q.size()){
            int v  = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(auto it: adj[v]){
                if(dis[it.first] > distance +it.second ){
                    dis[it.first] = distance +it.second;
                    q.push({it.first, dis[it.first]});
                }
            }
            
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i]==1e9)dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends