class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0, j = 0, n = s.size();
        while (i < n) {
            while (i < n && !isalnum(s[i]))
                i++;
            if (i < n) {
                char temp = tolower(s[i]);
                s[j] = temp;
                j++;
                i++;
            }
        }
        return checkPalindrome(s, 0, j);
    }

    bool checkPalindrome(string S, int st, int end) {
        for (int i = 0; i < end / 2; i++) {
            if (S[i] != S[end - i - 1]) {
                return false;
            }
        }
        return true;
    }
};