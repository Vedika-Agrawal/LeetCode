class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mn = -1, mx =-1, left = -1;
        long long ans  = 0;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            if(ele == minK) mn = i ;
            if(ele == maxK) mx = i;
            if(ele< minK || ele>maxK) left =  i;

            ans += max(0, min(mn, mx)-left);
        }
        return ans;
    }
};