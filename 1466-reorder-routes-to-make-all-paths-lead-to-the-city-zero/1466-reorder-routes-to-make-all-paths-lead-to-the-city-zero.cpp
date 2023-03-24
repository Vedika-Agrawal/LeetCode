class Solution {
public:
    int ans =0 ;
    
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[abs(it)]){
                if(it>0 )ans++;
                    dfs(abs(it),vis,adj);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& road) {
        vector<vector<int>>adj(n);
    
        vector<int>vis(n,0);
        
        for(auto it : road){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        
        dfs(0, vis, adj);
        return ans;
        
    }
};