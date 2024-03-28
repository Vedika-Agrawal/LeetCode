class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0 , j = 0 , n = nums.size();
        unordered_map<int, int>mp;
        int ans =  0;
        while(i<n){
            mp[nums[i]]++;
            while(mp[nums[i]] > k && j<i){
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};