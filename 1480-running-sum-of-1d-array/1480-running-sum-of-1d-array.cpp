class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int curr = 0;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            v.push_back(curr);
        }
        return v;
    }
};