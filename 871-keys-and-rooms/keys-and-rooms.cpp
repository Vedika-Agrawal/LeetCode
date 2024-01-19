class Solution {
public:
    vector<int>vis;
    void dfs(int node, vector<int>adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it]==0){
                dfs(it, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.resize(n,0);
        vector<int>adj[n];
        for(int i =0;i<n;i++){
            for(auto it: rooms[i]){
                adj[i].push_back(it);
            }
           
        }
        dfs(0,adj);
        return accumulate(vis.begin(),vis.end(), 0)== n;
    }
};