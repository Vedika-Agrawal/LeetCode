class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, vector<int>& memo, int idx) {
        if (idx >= days.size()) return 0;
        if (memo[idx] != -1) return memo[idx];

        // 1-day pass
        int oneDayPass = costs[0] + solve(days, costs, memo, idx + 1);

        // 7-day pass
        int next7 = idx;
        while (next7 < days.size() && days[next7] < days[idx] + 7) next7++;
        int sevenDayPass = costs[1] + solve(days, costs, memo, next7);

        // 30-day pass
        int next30 = idx;
        while (next30 < days.size() && days[next30] < days[idx] + 30) next30++;
        int thirtyDayPass = costs[2] + solve(days, costs, memo, next30);

        // Update memo with the minimum cost for the current index
        memo[idx] = min({oneDayPass, sevenDayPass, thirtyDayPass});
        return memo[idx];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        vector<int> memo(days.size(), -1);
        return solve(days, costs, memo, 0);
    }
};