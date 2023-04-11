class Solution {
public:
int numEnclaves(vector<vector<int>>& grid) {
int n = grid.size();
int m = grid[0].size();
vector<vector<int>>vis(n,vector<int>(m,0));
queue<pair<int,int>>q;
for(int i=0;i<n;i++){
for(int j =0;j<m;j++){
if(i==0 || j==0 || i==n-1 || j==m-1){
if(grid[i][j]==1){
q.push({i,j});
vis[i][j]=1;
}
}
}
}
int dir[5]={-1, 0 , 1, 0 ,-1};
while(q.size()>0){
int i = q.front().first;
int j = q.front().second;
q.pop();
for(int k=0;k<4;k++){
int ni = i + dir[k];
int nj = j + dir[k+1];
if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
q.push({ni,nj});
vis[ni][nj]=1;
}
}
}
int cnt= 0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid[i][j]==1 && vis[i][j]==0)cnt++;
}
}
return cnt;
}
};