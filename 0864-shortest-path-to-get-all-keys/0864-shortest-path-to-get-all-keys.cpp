class Solution {
public:
    
    vector<int>dir = { -1,0,1,0,-1};
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>>q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }
                else if(grid[i][j]>='a'  && grid[i][j]<='z')cnt++;
            }
        }
        
        int key = pow(2, cnt)-1;
        
        int vis[n][m][key+1];
        
        memset(vis,0,sizeof(vis));
        
        while(q.size()){
            int i = q.front()[0];
            int j =q.front()[1];
            int step =q.front()[2];
            int curr =q.front()[3];
            q.pop();
            
            if(curr== key)return step;
            
            for(int k=0;k<4;k++){
                int nr = dir[k]+i;
                int nc  = dir[k+1]+j;
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!='#'){
                    char ch = grid[nr][nc];
                    // Lock
                    if(ch>='A' && ch<='Z'){
                        if(vis[nr][nc][curr]==0 && (( curr >> (ch-'A')) & 1)==1){
                            vis[nr][nc][curr]=1;
                            q.push({nr,nc,step+1,curr});
                        }
                    }
                    // key
                    else if(ch>='a' && ch<='z'){
                        int nkey = curr | (1 << (ch-'a'));
                        if(vis[nr][nc][nkey]==0 ){
                             vis[nr][nc][nkey]=1;
                            q.push({nr,nc,step+1,nkey});
                        }
                    }
                    // empty
                    else{
                        if(vis[nr][nc][curr]==0 ){
                             vis[nr][nc][curr]=1;
                            q.push({nr,nc,step+1,curr});
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};