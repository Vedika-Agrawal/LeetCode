class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), false);
        dp[n - 1] = true;

        for (int idx = n - 1; idx >= 0; idx--) {

            for (int i = 1; i <= nums[idx]; i++) {
                if (idx + i < n && dp[idx + i] == true)
                    dp[idx] = dp[idx + i];
            }

        }
        return dp[0];
    }
};