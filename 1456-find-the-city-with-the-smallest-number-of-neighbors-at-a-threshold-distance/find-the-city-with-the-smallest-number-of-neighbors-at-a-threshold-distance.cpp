class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(auto it : edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++)dis[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX)continue;
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        
        int cntCity =n, cityNo =-1;
        
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int adjCity =0; adjCity<n;adjCity++){
                if(dis[i][adjCity] <= thres)cnt++;
            }
            if(cnt<=cntCity){
                cntCity=cnt;
                cityNo = i;
            }
        }
        return cityNo;
        
    }
};