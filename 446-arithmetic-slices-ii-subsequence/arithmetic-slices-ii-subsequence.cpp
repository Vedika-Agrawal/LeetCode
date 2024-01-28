class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);

        int result = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = 1ll * nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff] + 1;
                    result += dp[j][diff];
                } else {
                    dp[i][diff] += 1;
                }
            }
        }

        return result;
    }
};
