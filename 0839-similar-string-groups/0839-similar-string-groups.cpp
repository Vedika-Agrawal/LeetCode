class Solution {
public:
    bool isSimilar(string &a, string &b){
        int n = a.size();
        int diff= 0 ;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])diff++;
        }
        return diff ==2 || diff ==0;
    }
    
    void dfs(int node, vector<int>&vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int cnt = 0 ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};