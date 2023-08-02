//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int>dir = {-1,0,1,0,-1};
 
    int shortestDistance(int n, int m, vector<vector<int>> mat, int x, int y) {
        queue<pair<int,int>>q; 
        if(mat[0][0]==0) return -1;
        
        int level=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(q.size()){
            int sz  =q.size();
            while(sz--){
                int r  = q.front().first;
                int c  = q.front().second;
                q.pop();
                if(r==x && c==y)return level;
                for(int k = 0;k<4;k++){
                    int nr  = dir[k]+r;
                    int nc  = dir[k+1]+c;
                    if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1 && vis[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends