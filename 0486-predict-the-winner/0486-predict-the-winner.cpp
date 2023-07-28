class Solution {
public:
    
       
    int solve(vector<int>&nums, int i, int j, int flag){
        if(i>j) return 0;
        if(i==j)return nums[i];
       
          int var = 0 ;
        
        if(flag==0){
            
            var += max(nums[i] + solve(nums, i+1, j, 1) ,  nums[j] + solve(nums, i, j-1,1 ));
        }
        else{
        
            var  += min(- nums[i] + solve(nums, i+1, j, 0) ,  -nums[j] + solve(nums, i, j-1,0));
        }
        return var ;
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 0)>=0;
    }
};