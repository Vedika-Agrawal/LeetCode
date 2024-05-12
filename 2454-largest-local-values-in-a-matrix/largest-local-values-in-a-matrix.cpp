class Solution {
public:

    int solve(vector<vector<int>>&grid, int i ,int j){
        int mx = -1e9;
        for(int r = i ; r< i+3; r++){
            for(int c = j ; c < j+3; c++){
                mx = max(mx, grid[r][c]);
            }
        }
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        int n = grid.size();
        int m = grid[0].size();
        for(int i= 0 ;i< n-2;i++){
            vector<int>temp;
            for(int j = 0 ; j<m-2; j++ ){
                int value = solve(grid, i , j);
                temp.push_back(value);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};