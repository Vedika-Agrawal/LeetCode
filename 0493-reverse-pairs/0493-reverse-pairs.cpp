class Solution {
public:
    int ans;
    void merge(int low,int mid,int high,vector<int>& nums){
        int left=low,right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if((long long)nums[left]>((long long)2*nums[right])){
                ans+=(mid-left+1);
                right++;
            }
            else{
                left++;
            }
        }
        left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void mergeSort(int low,int high,vector<int> &nums){
        int ans=0;
        if(low<high){
            int mid=(low+high)/2;
            mergeSort(low,mid,nums);
            mergeSort(mid+1,high,nums);
            merge(low,mid,high,nums);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        ans=0;
        mergeSort(0,n-1,nums);
        return ans;
    }
};