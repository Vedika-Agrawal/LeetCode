class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, j = 0, n = houses.size(), m = heaters.size();
        int ans = 0; // Initialize ans to 0 instead of 1e9

        while (i < n) {
            while (j < m && houses[i] > heaters[j]) j++;
            int res = INT_MAX; // Initialize res to maximum value

            if (j - 1 >= 0) {
                int temp = abs(houses[i] - heaters[j - 1]);
                res = min(res, temp);
            }
            if (j < m) {
                int temp = abs(houses[i] - heaters[j]);
                res = min(res, temp);
            }
            ans = max(ans, res); // Update the maximum radius
            i++;
        }

        return ans;
    }
};
