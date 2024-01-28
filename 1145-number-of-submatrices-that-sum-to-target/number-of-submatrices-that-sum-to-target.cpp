class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            // int currSum = 0;
            for (int j = 0; j < m; j++) {
                // currSum += matrix[i][j];
                matrix[i][j] += j>0 ? matrix[i][j-1] : 0;
            }
        }
        int ans = 0;
        for (int st_col = 0; st_col < m; st_col++) {
            for (int col = st_col; col < m; col++) {
                unordered_map<int, int> mp;
                mp[0]++;
                int currSum = 0;
                for (int st_row = 0; st_row < n; st_row++) {
                    currSum = currSum + matrix[st_row][col];
                    if(st_col!=0) currSum -= matrix[st_row][st_col-1];
                    if (mp.count(currSum-target) != 0) {
                        ans += mp[currSum - target ];
                    }
                    mp[currSum]++;
                }
            }
        }
        return ans;
    }
};