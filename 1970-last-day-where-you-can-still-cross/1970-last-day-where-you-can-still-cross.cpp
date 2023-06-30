class Solution {
public:
    int n,m;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row,m=col;
        vector<vector<int>> grid(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m));
        int low=1,high=n*m;
        int ans;
        while(low<=high){
            grid.resize(n,vector<int>(m));
            vis.resize(n,vector<int>(m));
            int mid=low+(high-low)/2;
            for(int i=0;i<mid;i++){
                int x=cells[i][0]-1;
                int y=cells[i][1]-1;
                grid[x][y]=1;
            }
            queue<pair<int,int>> q;
            for(int j=0;j<m;j++){
                if(grid[0][j]==0){
                    q.push({0,j});
                    vis[0][j]=1;
                }
            }
            int a=-1;
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x==n-1){
                    a=1;
                    break;
                }
                for(int i=0;i<4;i++){
                    int nr=dr[i]+x,nc=dc[i]+y;
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            if(a!=-1){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            grid.clear();
            vis.clear();
        }
        return ans;
    }
};