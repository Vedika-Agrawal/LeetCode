class Solution {
public:
    
    int solve(vector<int>&nums, int l, int r){
         if(l>r)return INT_MIN;

        if(l==r)return nums[l];
        int mid = (r+l)/2;
        int leftMax =0, rightMax= 0, currSum =0;
        for(int i=mid-1; i>=l; i--){
            currSum += nums[i];
            leftMax = max(currSum, leftMax);
        }
        currSum =0;
        for(int i=mid+1; i<=r; i++){
            currSum += nums[i];
            rightMax = max(currSum, rightMax);
        }
       return max({solve(nums,l,mid-1),solve(nums,mid+1,r), leftMax+rightMax+nums[mid]});
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n-1);
    }
};


