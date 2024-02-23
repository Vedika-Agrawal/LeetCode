class Solution {
public:
    long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        long res = 0;
        TrieNode* root = new TrieNode();
        unordered_map<char, vector<int>> map;
        for (int i = n - 1; i >= 0; i--) {
            res += search(root, words[i]);
            if (sameCharacter(words[i])) {
                insert(root, words[i], words[i].length(), true);
                continue;
            }
            insert(root, words[i], words[i].length(), false);
            int length = kmp(words[i]);
            while (length > 0) {
                insert(root, words[i], length, false);
                length = kmp(words[i].substr(0, length));
            }
        }
        return res;
    }

private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
        int count = 0;
    };

    bool sameCharacter(string s) {
        char cha = s[0];
        for (char c : s) {
            if (c != cha) return false;
        }
        return true;
    }

    int kmp(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int i = 0, j = 1;
        while (j < n) {
            if (s[i] == s[j]) {
                dp[j] = i + 1;
                i++;
                j++;
            } else {
                if (i > 0) i = dp[i - 1];
                else j++;
            }
        }
        return dp[n - 1];
    }

    void insert(TrieNode* root, string s, int length, bool isSameCharacter) {
        TrieNode* node = root;
        for (int i = 0; i < length; i++) {
            int idx = s[i] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            if (isSameCharacter) node->count++;
        }
        node->isEnd = true;
        if (!isSameCharacter) node->count++;
    }

    int search(TrieNode* root, string s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }
        return node->count;
    }
};
