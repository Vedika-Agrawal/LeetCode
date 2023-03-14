class Solution {
public:
    queue<pair<pair<int,int>,int>>q;
    void solve(vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& ans, int time){
        
        while(q.size()>0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            ans[i][j] = t ;
            q.pop();
            int arr[5]= {-1, 0 , 1, 0, -1};
            for(int k=0;k<4;k++){
                int ni = i + arr[k];
                int nj = j + arr[k+1];
                
                if(ni>=0 && nj>=0 && ni<mat.size() && nj<mat[0].size() && !vis[ni][nj]){
                    vis[ni][nj]=1;
                    q.push({{ni,nj}, t+1});
                }
                
                
            }
        }
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        solve(mat,vis,ans,0);
        return ans;
    }
};