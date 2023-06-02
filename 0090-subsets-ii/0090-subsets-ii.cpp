class Solution {
public:
    int n;
   set<vector<int>> ans;
    void solve(vector<int>& nums, int i, vector<int>temp){
        // cout<<i<<endl;
        if(i==n){
            sort(temp.begin(),temp.end());

            ans.insert(temp);
        
            return ;
        }
        
        solve(nums, i+1, temp);
        temp.push_back(nums[i]);
        solve(nums, i+1, temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
       vector<int>temp;
        solve(nums,0,temp);
        vector<vector<int>> res;
        for(auto it: ans){
            res.push_back(it);
        }
        return res;
    }
};