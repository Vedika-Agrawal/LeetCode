class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==tar)return  mid;
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=tar && nums[mid]>tar){
                    hi= mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(nums[mid]<tar && nums[hi]>=tar) lo = mid+1;
                else{
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};