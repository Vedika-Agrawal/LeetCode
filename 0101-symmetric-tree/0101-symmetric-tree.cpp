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
    bool solve(TreeNode* l, TreeNode* r){
        if((!l && r) || (l && !r))return false;
        if(!l && !r){
            return true;
        }
        if(l->val != r->val)return false;
        
        if( (solve(l->left , r->right)) && (solve(l->right, r->left)) )return true;
         
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};