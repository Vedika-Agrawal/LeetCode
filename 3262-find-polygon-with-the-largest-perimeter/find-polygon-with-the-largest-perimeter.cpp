class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans  = -1;
        long long prev_sum = nums[1] + nums[0];

        for(int i =2;i<nums.size();i++){
            if(nums[i]< prev_sum) ans = nums[i] + prev_sum;
            prev_sum += nums[i];
        }
        return ans;
    }
};
