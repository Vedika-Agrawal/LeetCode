class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans,adj(n,0);
        for(auto it : edges){
            adj[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(adj[i]==0)ans.push_back(i);
        }
        return ans;
    }
};