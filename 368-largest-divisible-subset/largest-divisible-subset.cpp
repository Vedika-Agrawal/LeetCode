class Solution {
public:
    vector<int> ans;
    unordered_map<int, vector<int>> memo; // Memoization table

    vector<int> solve(vector<int>& nums, int idx, int prev) {
        int key = idx * nums.size() + prev;
        if (memo.find(key) != memo.end()) {
            return memo[key]; // If the result for this state is already computed, return it
        }

        vector<int> temp;
        if (idx >= nums.size()) {
            return temp;
        }

        vector<int> withoutCurrent = solve(nums, idx + 1, prev);

        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            vector<int> withCurrent = solve(nums, idx + 1, idx);
            withCurrent.push_back(nums[idx]);

            if (withCurrent.size() > withoutCurrent.size()) {
                memo[key] = withCurrent; // Update memoization table
                return withCurrent;
            }
        }

        memo[key] = withoutCurrent; // Update memoization table
        return withoutCurrent;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return solve(nums, 0, -1);
    }
};