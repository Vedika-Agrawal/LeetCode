class Solution {
public:
    int n,m;
    vector<int> row={-1,0,1,-1,1,-1,0,1};
        vector<int> col={1,1,1,0,0,-1,-1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue< pair< pair<int,int> , int >>q;
        int i = 0, j = 0;
        if(grid[i][j]==1)return -1;
        vis[0][0]=1;
        q.push({{i,j},1});
        
        while(q.size()>0){
            int sz =  q.size();
            
            
            while(sz--){
                auto it = q.front();
                i = it.first.first;
                j = it.first.second;
                int ans  = it.second;

                if(i==n-1 && j==m-1)return ans;

                q.pop();
                for(int k=0;k<8;k++){
                    int nr  = i + row[k];
                    int nc = j + col[k];
                    
                    if(nr>=0 &&nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==0){
                        vis[nr][nc]=1;
                        cout<<nr<<" "<<nc<<" "<<ans<<endl;
                        q.push({  {nr,nc}, ans+1});
                    }
                }
                
            }
        }
        return -1;
    }
};