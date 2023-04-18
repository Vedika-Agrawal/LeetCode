class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>adj[n];
        vector<int>indeg(n,0);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        queue<int>q;
        vector<vector<int>>dp(n,vector<int>(26,0));
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }
        
        int ans = 0;
        int cntNodes= 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cntNodes++;
            
            ans = max(ans, dp[node][colors[node]-'a']);
            
            for(int it : adj[node]){
                for(int i=0;i<26;i++){
                    dp[it][i] = max(dp[it][i] , dp[node][i] + (colors[it]-'a'==i));
                }
                 indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
            }
           
        }
        if(cntNodes<n)return -1;
        return ans;
    }
};