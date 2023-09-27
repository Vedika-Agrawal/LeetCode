class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                idx++;
                if (idx == k) {
                    return string(1, s[i]);
                }
            } else {
                int multi = s[i] - '0';
                if (idx * multi >= k) {
                    // We've found the range in which k falls.
                    // Recursively decode within this range.
                    return decodeAtIndex(s, k % idx == 0 ? idx : k % idx);
                }
                idx *= multi;
            }
        }
        return "";
    }
};
