class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& plane, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        
        for(auto it : plane){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dis(n,1e9);
        dis[src] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
             auto it = q.front();
            q.pop();
            int stop = it.first;
            int v = it.second.first;
            int wt = it.second.second;
            
            for(auto it: adj[v]){
                int adjNode = it.first;
                int cost = it.second;
                
                if(cost + wt < dis[adjNode] && stop<=k){
                    dis[adjNode]= cost + wt;
                    q.push({stop+1, {adjNode,cost+wt}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        return dis[dst];
        
        
    }
};