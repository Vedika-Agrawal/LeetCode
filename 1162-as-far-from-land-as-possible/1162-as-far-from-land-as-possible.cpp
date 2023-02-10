class Solution {
public:
    
    const pair<int,int> dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int visited[grid.size()][grid[0].size()];
        queue<pair<int,int>>q;
        
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                visited[i][j] = grid[i][j];
                
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        
        
        int dis = -1;
        
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                pair<int,int>temp = q.front();
                q.pop();
                for(pair<int,int>it :dir ){
                    int x = temp.first + it.first;
                    int y = temp.second + it.second;
                    
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && visited[x][y]==0){
                        visited[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            dis++;
        }
        return dis==0?-1:dis;
        
    }
};