class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans  = 0;
        for(int i=0;i<nums.size();i++){
            set<int>s = {nums[i]};
            int cur  =0 ;
            for(int j = i+1; j< nums.size(); j++){
                cur += s.count(nums[j]) ? 0 : 1 - s.count(nums[j] + 1) - s.count(nums[j] - 1);
                s.insert(nums[j]);
                ans += cur;
            }
        }
        return ans;
    }
};

