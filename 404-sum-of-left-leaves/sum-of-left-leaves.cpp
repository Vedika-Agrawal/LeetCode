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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    int ans = 0;
    void solve(TreeNode* root){
        if(!root)return ;
        if(root->left){
            if(isLeaf(root->left)){
                ans += root->left->val;
            }
            else{
                solve(root->left);
            }
        }
        solve(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return ans;
    }
};