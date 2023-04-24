class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0 ;
        int i= 0; int j= 0;
        while(j<nums.size()){
            while(j<nums.size() && sum<target){
                sum+=nums[j];
                j++;
            }
            
            while(sum>=target){
                ans = min(ans,j-i);
                sum-=nums[i];
                i++;
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};