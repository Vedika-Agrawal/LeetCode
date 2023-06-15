class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector< pair<int,int>>>adj(n);
        // int ans = INT_MAX;
        vector<int> dist(n, INT_MAX);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // queue<pair<int,pair<int,int>>>q;
        
        queue<pair<int,int>>q;
        q.push({src,0});
        int level  = 0;
        
        while(level<=k && q.size() ){
            
            
            int sz = q.size();
            
            
//             while(sz--){
//                 int node = q.front().first;
//                 int dis  =q.front().second;
//                 q.pop();
//                 for(auto it: adj[node]){
                    
//                     if(it.second +dis >= distance[node]) continue;
//                     distance[node ]= it.second+dis;
//                     q.push({it.first, distance[node]});
//                 }
//             }
             while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            
            level++;
            
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};