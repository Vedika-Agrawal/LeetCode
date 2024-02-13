class Solution {
public:
    int mod = 1e9+7;
    int totalSum;
    int n;
    int solve( vector<int>&prefixSum) {
        int cnt = 0;
        for (int left = 0; left < n-2; left++) {
            int leftSum = prefixSum[left];

            int midEnd = (totalSum - leftSum)/2;
            int low = lower_bound(prefixSum.begin()+left+1, prefixSum.end(), leftSum *2)-prefixSum.begin();
            int up = upper_bound(prefixSum.begin()+ left + 1, prefixSum.begin()+n -1, midEnd+leftSum)-prefixSum.begin();
            if(up - low >0) cnt = (cnt + up - low)% mod;
        }
        return cnt%mod;;
    }
    int waysToSplit(vector<int>& nums) {
        n = nums.size();
        for(int i =1;i<n;i++) nums[i] += nums[i-1];
        totalSum += nums[n-1];
        return solve(nums);
    }
};


