class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>adj(n,0);
        for(auto it: roads){
           int u = it[0];
           int v = it[1];
           adj[u]++;
           adj[v]++;
        }
        sort(adj.rbegin(), adj.rend());
        long long ans  = 0;
        for(auto it: adj){
            ans += it*n;
            n--;
        }
        return ans;
    }
};