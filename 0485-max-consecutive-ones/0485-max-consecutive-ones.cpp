class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            
            if(nums[i]==1){
                int cnt = 0 ;
                while(i<n && nums[i]==1){cnt++;i++;}
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};