class Solution {
public:
    int n;
    vector<vector<int>>ans;
    
    void solve(vector<int>can, int idx, int tar, vector<int>&temp){
        if(tar==0){
            ans.push_back(temp);
            return ;
        }
        if(idx>=n)return ;
        
        
        
        // nottake 
        int j = idx;
        while(j<n && can[j]==can[idx])j++;
        
        solve(can, j, tar , temp );
        
        // take 
        if(tar-can[idx]>=0){
             temp.push_back(can[idx]);
            solve(can, idx+1, tar-  can[idx], temp);
            temp.pop_back();

        }
       
        
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
       n = can.size() ;
        vector<int>temp;
        sort(can.begin(),can.end());
        solve(can, 0, tar, temp);
        return ans;
    }
};