class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, int>> q;
        k++;
        q.push({src, 0});
        vector<int> dis(n, 1e9);
        dis[src] = 0;

        while (k > 0) {
            int sz = q.size() ;
                while (sz--) {
                    int node = q.front().first;
                    int d = q.front().second;
                    q.pop();

                    for (auto it : adj[node]) {
                        if (dis[it.first] > d + it.second) {
                            dis[it.first] = d + it.second;
                            q.push({it.first, d + it.second});
                            cout << it.first << " " << it.second + d << endl;
                        }
                    }
                }
                k--;
                
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};