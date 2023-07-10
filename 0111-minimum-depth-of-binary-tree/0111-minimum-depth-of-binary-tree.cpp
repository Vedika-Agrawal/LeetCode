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
int solve(TreeNode* root){
    if(!root)return 0;
    int l =0, r= 0;
    l = solve(root->left)  ;
    r = solve(root->right) ;
    if(l==0)return r+1;
    if(r==0)return l+1;
    return 1+min(l,r);
}
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};