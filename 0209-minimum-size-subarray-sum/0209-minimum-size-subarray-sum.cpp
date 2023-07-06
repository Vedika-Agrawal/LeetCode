class Solution {
public:
    bool isPossible(vector<int>&arr,int k,int mid){
        int sum =0 ;
        for(int i=0;i<mid;i++)sum+=arr[i];
        int j = mid, i=0;
        int maxi=sum;
        while(j<arr.size()){
            sum-=arr[i];
            sum += arr[j];
            maxi = max(sum,maxi);
            
            i++;
            j++;
        }
        return maxi>=k;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 1, hi = nums.size();
        int ans =  0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isPossible(nums, target, mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};