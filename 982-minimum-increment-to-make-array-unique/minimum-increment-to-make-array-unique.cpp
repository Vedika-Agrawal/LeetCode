class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans  = 0 ;
        for(int i=0;i<nums.size(); i++){
           if(i>0 && nums[i-1]>=nums[i]){
            int diff = nums[i-1]- nums[i] + 1;
            ans += diff;
            nums[i] += diff;
           }
        }
        return ans ;
    }
};