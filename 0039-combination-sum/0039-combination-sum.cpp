class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(vector<int>& can, int target, int idx, vector<int> temp){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(idx==n)return ;
        
        
        solve(can,target, idx+1, temp);
        temp.push_back(can[idx]);
        if(target-can[idx] >=0)
        solve(can,target - can[idx], idx, temp);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<int>temp;
        n = can.size();
        solve(can, tar, 0, temp );
        return ans;
    }
};