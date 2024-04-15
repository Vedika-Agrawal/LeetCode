/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total = 0;
    void solve(TreeNode* root, string ans){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            char ch = root->val + '0';
            ans += ch;
            int val = stoi(ans);
            cout<<val<<endl;
            total += val;
            return;
        }
        char ch = root->val + '0';
        ans += ch;
        solve(root->left, ans);
        solve(root->right,ans);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return total;
    }
};