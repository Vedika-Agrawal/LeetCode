class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int y = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        if(x>= nums.size() || nums[x]!=target) return {-1,-1};
        // if(y>= nums.size() || nums[y]!=target)y = -1;
        return {x,y-1};
    }
};