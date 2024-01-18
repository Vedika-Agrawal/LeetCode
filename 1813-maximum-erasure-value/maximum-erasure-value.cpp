class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0, ans =0;
        int curr = 0;
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            curr += nums[j];
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                curr -= nums[i];
                
                i++;
                
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};