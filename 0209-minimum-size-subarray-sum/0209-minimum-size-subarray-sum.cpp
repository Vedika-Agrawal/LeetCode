class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int i=0, j=0, n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum>=tar){
                ans = min(ans,j-i+1); 
                sum-= nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)
        ans =0;
        return ans;
        
        
    }
};