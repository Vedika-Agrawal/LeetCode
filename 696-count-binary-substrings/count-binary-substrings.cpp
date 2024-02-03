class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int zero = 0, one = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                ans += min(zero, one);
                if (s[i] == '0') {
                    zero = 1;
                } else {
                    one = 1;
                }
            } else {
                if (s[i] == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
        }

        ans += min(zero, one);

        return ans;
    }
};
