class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =  nums.size();
        int i=0,k=0,j=n-1;
        while(i<=j){
            if(nums[i]==0) swap(nums[i++],nums[k++]);
            else if(nums[i]==2) swap(nums[i], nums[j--]);
            else i++;
        }
    }
};