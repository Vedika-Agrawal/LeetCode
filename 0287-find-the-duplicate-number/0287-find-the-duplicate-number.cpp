class Solution {
public:
    int solve(vector<int>&nums, int l , int h){
        while(l<=h){
            int mid = (l+h)/2;
            int cnt =0;
            for(auto it : nums){
             if(mid>=it)cnt++;   
            }
            if(cnt<=mid){
                l = mid+1;
            }
            else 
                h = mid-1;
        }
        return l;
        
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,1,n-1);
    }
};