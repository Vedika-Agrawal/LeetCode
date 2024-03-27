class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0;
        int ans  = 0 ;
        int pro = 1;
        int i = 0, j  = 0, n = nums.size();

        while(i<n){
            pro *= nums[i];
            while(j<=i && pro>=k){
                pro/=nums[j];
                j++;
            }
            if(pro<k)ans +=( i-j+1);
            i++;
        }
        return ans;
    }
};