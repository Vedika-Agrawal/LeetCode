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
    
    int ans = 0;
    void solve(TreeNode * root , int l, int r){
        if(!root){
            ans = max(ans,l);
            ans = max(ans,r);
            return ;
        }
        solve(root->left, 0,l+1);
        solve(root->right, r+1 , 0);
    }
    int longestZigZag(TreeNode* root) {

        solve(root, 0,0);
        return ans-1;
    }
};