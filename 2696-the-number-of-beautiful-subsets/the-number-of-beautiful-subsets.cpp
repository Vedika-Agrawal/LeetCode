class Solution {
public:
    // Function to validate if adding 'ele' to the subset 'v' still keeps it beautiful
    bool isValidate(vector<int>& v, int ele, int k, vector<int>& nums) {
        for (int x : v) {
            if (abs(x - ele) == k) return false;
        }
        return true;
    }

    // Recursive function to generate subsets and count beautiful ones
    int solve(vector<int>& nums, int idx, vector<int>& v, int k) {
        if (idx >= nums.size()) {
            return v.empty() ? 0 : 1; // Return 1 for non-empty beautiful subset
        }
        
        // Skip the current element
        int notTake = solve(nums, idx + 1, v, k);
        
        // Include the current element if it's valid
        int take = 0;
        if (isValidate(v, nums[idx], k, nums)) {
            v.push_back(nums[idx]);
            take = solve(nums, idx + 1, v, k);
            v.pop_back();
        }
        
        return notTake + take;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> v;
        return solve(nums, 0, v, k);
    }
};
