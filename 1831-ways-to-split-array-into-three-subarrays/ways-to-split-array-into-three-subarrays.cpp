class Solution {
public:
    int mod = 1e9+7;
    vector<int> prefixSum;
    int totalSum;
    int n;
    int solve() {
        int cnt = 0;
        for (int left = 0; left < n-2; left++) {
            int leftSum = prefixSum[left];

            int midEnd = (totalSum - leftSum)/2;
            int low = lower_bound(prefixSum.begin()+left+1, prefixSum.end(), leftSum*2)-prefixSum.begin();
            int up = upper_bound(prefixSum.begin() + low, prefixSum.begin()+n-1, midEnd+leftSum)-prefixSum.begin();
            cnt = (cnt + up - low)% mod;
        }
        return cnt%mod;;
    }
    int waysToSplit(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (auto it : nums) {
            sum += it;
            prefixSum.push_back(sum);
        }
        totalSum += prefixSum[n-1];
        return solve();
    }
};

