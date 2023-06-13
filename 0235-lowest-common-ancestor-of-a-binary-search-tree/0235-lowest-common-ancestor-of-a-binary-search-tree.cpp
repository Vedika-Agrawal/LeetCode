/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root,int l, int r){
        if(root==NULL)return root;
        if(root->val ==l || root->val==r)return root;
        if(root->val > l && root->val < r)return root;
        else if(root->val >l && root->val > r)
            return solve(root->left, l,  r);
        else
            return solve(root->right, l, r);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        // if(root->val == p->val || root->==q->val)return root;
        int a = p->val;
        int b = q->val;
        // if(a>b){swap(a,b)};
        if(a>b){
            int c =  a;
            a= b;
            b=c;
        }
        return solve(root, a, b);
        
    }
};