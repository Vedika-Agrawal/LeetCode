class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j= 0, ans  = 0,  cnt  = 0;
        for(; j<nums.size(); j++){
            if(nums[j]==0)cnt++;
            while(cnt>1){
                if(nums[i]==0)cnt--;
                i++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};