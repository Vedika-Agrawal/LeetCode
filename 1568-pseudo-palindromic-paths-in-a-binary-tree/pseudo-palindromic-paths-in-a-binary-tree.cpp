class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root) return 0;
        vector<int> mp(10, 0); // Initialize count array for each path
        return dfs(root, mp);
    }

private:
    int dfs(TreeNode* root, std::vector<int>& mp) {
        if (!root) return 0;

        // Increment count for the current digit
        mp[root->val]++;

        if (!root->left && !root->right) {
            int cnt = 0;
            for (int i = 1; i <= 9; ++i) {
                if (mp[i] % 2 != 0) cnt++;
            }

            // Reset the count for the current digit
            mp[root->val]--;

            if (cnt > 1) return 0;
            else return 1;
        }

        int leftCount = dfs(root->left, mp);
        int rightCount = dfs(root->right, mp);

        // Reset the count for the current digit
        mp[root->val]--;

        return leftCount + rightCount;
    }
};