class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i<n){
            if(i+1<n && nums[i]==nums[i+1])i++;
            else{
                swap(nums[i++],nums[j++]);
            }
        }
        if(i!=j)
        swap(nums[j], nums[n-1]);
        return j;
    }
};