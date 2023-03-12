class Solution {
public:
    
    void dfs(int start, vector<int>&vis, vector<int>list[]){
        vis[start]=1;
        for(auto it : list[start]){
            if(!vis[it]){
                dfs(it, vis, list);
            }
        }
    }
    
    void bfs(int start, vector<int>&vis, vector<int>list[]){
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(q.size()>0){
            int node = q.front(); q.pop();
            for(auto it : list[node]){
                
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        vector<int>list[v.size()];
       
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i!=j && v[i][j]==1){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(v.size(), 0);

        int cnt = 0;
        for(int i=0; i<v.size();i++){
            if(!vis[i]){
                cnt++;
                bfs(i, vis, list);
            }
        }
        return cnt;
        
    }
};