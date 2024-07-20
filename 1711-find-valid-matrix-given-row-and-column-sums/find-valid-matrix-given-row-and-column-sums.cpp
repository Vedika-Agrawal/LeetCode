class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i = 0, j =  0;
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>>v(n, vector<int>(m, 0));

        while(i<n && j<m){
            int mn = min(rowSum[i], colSum[j]);
            v[i][j] = mn;
            rowSum[i] -= mn;
            colSum[j] -= mn;
            if(rowSum[i]==0)i++;
            if(colSum[j]==0)j++;
        }
        return v;
    }
};