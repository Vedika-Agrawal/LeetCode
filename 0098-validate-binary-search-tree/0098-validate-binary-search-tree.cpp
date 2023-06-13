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
    #define ll long long 
    ll prev  = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
       bool x = isValidBST(root->left);
        if(root){
            if(root->val<= prev)return false; 
            else{
                prev  = root->val;
            }
        }
         bool y = isValidBST(root->right);
        return x&& y;
        
        
    }
};