class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int i, vector<int>temp){
        if(i>=nums.size()){
            if(st.count(temp)==0)ans.push_back(temp);
            return;
        }
        solve(nums, i+1, temp);
        temp.push_back(nums[i]);
        solve(nums, i+1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(nums , 0, temp);
        return ans;
    }
};