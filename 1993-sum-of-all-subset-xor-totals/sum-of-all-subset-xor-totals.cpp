class Solution {
public:
    int ans  = 0 ;
    void solve(vector<int>&nums, int i, int res){
        if(i>=nums.size()){
            ans+=res;
            return ;
        }
        solve(nums, i+1, res);
        solve(nums, i+1, res^ nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return ans;
    }
};