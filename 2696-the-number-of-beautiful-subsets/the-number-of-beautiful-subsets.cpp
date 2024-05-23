class Solution {
public:
     bool isValidate(vector<int>& v, int ele, int k, vector<int>& nums) {
        for (int x : v) {
            if (abs(x - ele) == k) return false;
        }
        return true;
    }
 
    int solve(vector<int>&nums, int idx, vector<int>&v, int k){
        if(idx>=nums.size()){
            return v.size()>0 ? 1 : 0;
        }
        int notTake = solve(nums, idx+1, v, k);
        int take = 0;
        if(isValidate(v, nums[idx], k, nums)){
             v.push_back(nums[idx]);
             take  = solve( nums, idx+1, v, k);
             v.pop_back();
        }
        return take + notTake;
    }    

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>v;
        return solve(nums, 0, v, k);
    }
};