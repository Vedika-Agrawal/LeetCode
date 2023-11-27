class Solution {
public:
    const long MOD = 1e9 + 7;
int knightDialer(int n) {
    vector<vector<int>> nextButtons = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    vector<long> endsWith(10, 1);
    while(--n) { 
        vector<long> temp(10, 0);
        for(int curr = 0; curr < 10; curr++)
            for(int next : nextButtons[curr])
                temp[next] = (temp[next] + endsWith[curr]) % MOD;
        endsWith = temp;
    }
    return accumulate(endsWith.begin(), endsWith.end(), 0l) % MOD;
}
};