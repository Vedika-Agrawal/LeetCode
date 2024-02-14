class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

    }
};