class Solution {
public:
    bool isPossible(string s, vector<int>& chr) {
        for (auto it : s) {
            if (chr[it - 'a'] > 0) return false;
        }
        return true;
    }

    bool isUnique(string s) {
        unordered_set<char> uniqueChars;
        for (auto it : s) {
            if (uniqueChars.count(it) > 0) return false;
            uniqueChars.insert(it);
        }
        return true;
    }

    int solve(vector<string>& arr, int i, vector<int>& chr) {
        if (i == arr.size()) return 0;

        // Skip the current string
        int notTake = solve(arr, i + 1, chr);

        // Take the current string if it is unique and possible
        int take = 0;
        string temp = arr[i];

        if (isUnique(temp) && isPossible(temp, chr)) {
            for (auto it : temp) {
                chr[it - 'a']++;
            }
            take = temp.size() + solve(arr, i + 1, chr);
            for (auto it : temp) {
                chr[it - 'a']--;  // Backtrack
            }
        }

        return max(notTake, take);
    }

    int maxLength(vector<string>& arr) {
        vector<int> alp(26, 0);
        return solve(arr, 0, alp);
    }
};
