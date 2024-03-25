class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        for(int i = 0 ; i< nums.size(); i++){
            int ele = abs(nums[i]);
            if(nums[ele-1]<0) v.push_back(ele);
            else{
                nums[ele-1] = -nums[ele-1];
            }
        }
        return v;
    }
};