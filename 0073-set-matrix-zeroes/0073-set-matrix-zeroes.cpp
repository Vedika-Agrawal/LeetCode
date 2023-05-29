class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<pair<int,int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    mp.push_back({i,j});
                }
            }
        }
        for(auto it:mp){
                    int x=it.first;
                    int y=it.second;
                    for(int p=0;p<m;p++){
                        matrix[p][y]=0;
                    }
                    for(int q=0;q<n;q++){
                        matrix[x][q]=0;
                    }
                }
            }
        
};