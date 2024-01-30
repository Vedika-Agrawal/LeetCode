class Solution {
public:
  bool checkPalindrome(string S, int st, int end) {
        for (int i = 0; i < end / 2; i++) {
            if (S[i] != S[end - i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool isVaildChar(char ch) {
        if (ch >= 'a' && ch <= 'z')
            return true;
        else if (ch >= 'A' && ch <= 'Z')
            return true;
        else if (ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    bool isPalindrome(string&s) {
        int i = 0, j = 0, n = s.size();
        while (i < n) {
            while (i < n && isVaildChar(s[i]) == false)
                i++;
            if (i <n) {
                char temp = tolower(s[i]);
                s[j] = temp;
                j++;
                i++;
            } 
        }
        return checkPalindrome(s,0,j);
        return false;
    }
};