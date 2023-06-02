class Solution {
public:
    int ans = INT_MIN;
    #define ll long long
    double calculate(int x1,int y1, int x2, int y2){
        double dis = (ll)(x1-x2)*(ll)(x1-x2);
        dis += (ll)(y1-y2)*(ll)(y1-y2);
        return (dis);
    }
    
    
   void dfs(unordered_map<int,vector<int>>&graph,vector<bool> &visited,int &c,int &i)
    {
        visited[i]=true;
        c++;
        for(int j=0;j<graph[i].size();j++)
        {
            if(!visited[graph[i][j]])
             dfs(graph,visited,c,graph[i][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& bom) {
        int n = bom.size();
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x1 = bom[i][0];
                    ll y1 = bom[i][1];
                    ll r1 = bom[i][2];
                    
                    ll x2 = bom[j][0];
                    ll y2 = bom[j][1];
                    ll r2 = bom[j][2];
                    
                    double dis = calculate(x1,y1,x2,y2);
                    
                    // if(r1>=dis){
                    if ((ll)r1 * r1 >= dis) {
                        cout<<i<<" "<<j<<endl;
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
       int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=0;
            vector<bool> visited(n,false);
            dfs(adj,visited,c,i);
            ans=max(ans,c);
        }
        return ans;
    }
};