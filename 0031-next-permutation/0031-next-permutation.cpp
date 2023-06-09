class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size()-1;
        while(i>0 && nums[i] <= nums[i-1])i--;
        i--;
        if(i<0){
            reverse(nums.begin(),nums.end());
            return ;
        }
        cout<<i<<endl;
        int j = nums.size()-1;
        while(j >0 && nums[i]>=nums[j])j--;
        
        cout<<j<<endl;
    
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        
    }
};