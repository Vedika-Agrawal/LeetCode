class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,vector<int>>row,col;
        
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i].push_back(grid[i][j]);
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                col[j].push_back(grid[i][j]);
            }
        }
        
        int ans=0;
        for(auto it:row){
            for(auto jt:col){
                if(it.second==jt.second){
                ans++;
                }
            }
        }
        return ans;
        
    }
};