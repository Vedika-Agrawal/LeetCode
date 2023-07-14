class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = lower_bound(res.begin(), res.end(), nums[i])-res.begin();
        if(it==res.size()) res.push_back(nums[i]);
        else {
            res[it] = nums[i];
        }   
    }
    return res.size();
}
};