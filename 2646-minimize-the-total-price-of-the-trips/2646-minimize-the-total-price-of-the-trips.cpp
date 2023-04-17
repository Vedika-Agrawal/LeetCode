class Solution {
public:
    
    int freq[100];
    vector<int> adj[100];
    
    
    int cntNodes(int u, int v, int p){
        if(u==v){
            freq[v]++;
            return 1;
        }
        
        for(auto it : adj[u]){
            if(it!=p){
                if(cntNodes(it,v,u)){
                    freq[u]++;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    pair<int,int> solve(int u, int p , vector<int>&price){
        
        int taken = (price[u]/2)*(freq[u]);
        int notTaken = (price[u])*(freq[u]);
        
        for(auto it : adj[u]){
            if(it==p)continue;
            
            pair<int,int>childAns = solve(it,u,price);
            
            notTaken += min(childAns.first,childAns.second);
            taken += childAns.second;
        }
        
        return {taken,notTaken};

        
    }
    

    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        
         memset(freq,0, sizeof freq);
        
        
        // for(int i=0;i<n;i++){
        //     adj[i].clear();
        // }
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // cnt nodes how many time thery will apper 
        for(auto trip : trips){
            cntNodes(trip[0],trip[1], -1);
        }
        
        pair<int,int>ans = solve(0,-1,price);
        return min(ans.first,ans.second);
        
        
        
        
    }
};