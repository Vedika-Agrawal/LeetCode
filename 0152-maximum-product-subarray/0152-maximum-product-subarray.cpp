class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
       
        int n = nums.size();
        int pre = nums[0];
        int suff = nums[n-1] ;
        int ans  = max(pre,suff);
        pre = pre==0 ? 1 : pre;
        suff = suff==0 ? 1 : suff;
        for(int i=1;i<n;i++){
            ans = max(ans, pre * nums[i]);
            pre *= nums[i];
            pre = pre==0 ? 1 : pre;
        }
        
        for(int i=n-2;i>=0;i--){
            ans = max(ans, suff* nums[i]);
            suff*= nums[i];
            suff = suff==0 ? 1 : suff;
        }
        return ans;
    }
};