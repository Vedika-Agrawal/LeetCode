class Solution {
public:
    int atMost(vector<int>&nums, int k){
        int i=0, j =0, n = nums.size();
        int ans  = 0;
        unordered_map<int,int>mp;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;
            }
            ans += i-j;
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k==0)return 0;
        return atMost(nums, k) - atMost(nums, k-1);
    }
};