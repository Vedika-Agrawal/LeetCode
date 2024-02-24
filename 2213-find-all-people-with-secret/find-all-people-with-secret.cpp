class Solution {
public:
    unordered_map<int, vector<pair<int,int>>>mp;
    vector<int>vis;
    void dfs(int node, int time){
        for(auto it: mp[node]){
            if(it.second >= time && vis[it.first] > it.second ){
                vis[it.first] = it.second;
                dfs(it.first, it.second);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // mp[0].push_back({firstPerson, 0});
        for(auto it: meetings){
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }
        vis.resize(n, 1e9);
        vis[0] = 0 ;
        vis[firstPerson] = 0;
        dfs(firstPerson, 0);
        dfs(0,0);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i] != 1e9)
                ans.push_back(i);
        }
        return ans;
    }
};