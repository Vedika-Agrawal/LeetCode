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
    
    TreeNode* helper(TreeNode* root, int &k){
        if(root==NULL )return NULL;
        TreeNode* node = helper(root->left, k);
        if(node!=NULL)return node;
        k--;
        if(k==0)return root;
        return helper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // int cnt = 0;
        TreeNode * ans = helper(root, k );
        return ans ? ans->val : -1;
    }
};