class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans,copy = nums;
        sort(nums.rbegin(),nums.rend());
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        for(auto it : copy){
            if(mp[it]-- >0){
                ans.push_back(it);
            }
        }
        return ans;
    }
};