class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum =0 ;
        for(int i=0;i<n;i++){
            int idx = n-i-1;
            sum += (mat[i][i] + mat[i][idx] );
        }
        if(n%2!=0){
            
        
            int idx = n/2;
        sum-= mat[idx][idx];
        }
        return sum;
    }
};