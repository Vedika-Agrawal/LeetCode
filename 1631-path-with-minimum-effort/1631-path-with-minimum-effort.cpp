class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        int n = ht.size(), m = ht[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        pq.push({0,{0,0}});
        
        
         int dir[]={-1,0,1,0,-1};
        
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            
           pq.pop();
            
            if(r==n-1 && c==m-1)return diff;
            
            for(int i=0;i<4;i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newEffort = max(diff,abs( ht[r][c]-ht[nr][nc]));
                    
                    if(newEffort< dis[nr][nc]){
                        dis[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
        
    }
};