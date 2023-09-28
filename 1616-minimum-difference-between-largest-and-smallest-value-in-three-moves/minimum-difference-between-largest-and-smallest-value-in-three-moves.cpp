class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
    
        if(n<=3)return 0;
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        // pick all from from
        int temp = nums[n-1]- nums[3];
        ans = min(ans, temp);

        // pick all from end
         temp = nums[n-4]- nums[0];
        ans = min(ans, temp);

        // pick 1 from front and 2 from end
         temp = nums[n-3]- nums[1];
        ans = min(ans, temp);

        // pick 2  from front and 1 end
         temp = nums[n-2]- nums[2];
        ans = min(ans, temp);
        return ans;

    }
};