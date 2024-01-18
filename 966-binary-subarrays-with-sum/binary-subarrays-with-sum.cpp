class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int ans = 0, i =0;
            int sum  = 0, j=0;
            int n= nums.size();
            while(j<n){
                sum+=nums[j++];
                while(i<j &&  sum>goal){
                    sum-=nums[i++];
                }
                ans += j-i;
            }
            return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums,goal)- solve(nums,goal-1);
    }
};