class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)continue;
                if(i==0 || j==0) {
                    cnt+= mat[i][j];
                    continue;
                }
                int up = mat[i-1][j];
                int side = mat[i][j-1];
                int dig = mat[i-1][j-1];
                int mini = min({up, side, dig});
                
                mat[i][j] += mini;
                cnt+=mat[i][j];
            }
        }
        return cnt;
    }
};