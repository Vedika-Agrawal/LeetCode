class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int steps, int arrLen, int idx, int cnt) {
        if (cnt == steps && idx == 0) {
            dp[idx][cnt] = 1;
            return 1;
        }
        if (cnt > steps) return 0;
        if (idx < 0 || idx >= arrLen) return 0;

        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        long long a = solve(steps, arrLen, idx - 1, cnt + 1) % mod;
        long long b = solve(steps, arrLen, idx + 1, cnt + 1) % mod;
        long long c = solve(steps, arrLen, idx, cnt + 1) % mod;

        long long result = (a + b + c) % mod;
        return dp[idx][cnt] = result;
    }

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen,steps);
        dp.resize(arrLen, vector<int>(steps + 1, -1));
        return solve(steps, arrLen, 0, 0);
    }
};
