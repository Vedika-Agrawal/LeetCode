class Solution {
    vector<vector<unordered_map<int, int>>> mp;
    int solve(vector<vector<int>>& e, int k, int pre_end, int i)  {
        if(i >= e.size() || k == 0) return 0;
        if(mp[i][k].count(pre_end)) return mp[i][k][pre_end];
        mp[i][k][pre_end] = 0;
        if(pre_end < e[i][0]) 
            mp[i][k][pre_end]  = solve(e, k-1, e[i][1], i+1) + e[i][2];
        return mp[i][k][pre_end] = max(mp[i][k][pre_end] ,  solve(e, k, pre_end, i+1));
    }
public:
    int maxValue(vector<vector<int>>& e, int k) {
        sort(begin(e), end(e));
        mp.resize(e.size(), vector<unordered_map<int, int>>(k+1));
        return solve(e,k, -1, 0);
    }
};