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
    int res  = 0;
    class bst{
       public :
        bool isBst;
        int mn , mx, sum;
    };
    
    bst solve(TreeNode* root){
        
        if(!root) return {true, INT_MAX, INT_MIN,0};
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        if(l.isBst && r.isBst && l.mx < root->val && root->val < r.mn){
            int total = l.sum + r.sum + root->val;
            res = max(res, total);
            
            return {true, min(l.mn, root->val), max(r.mx , root->val), total};
        }
        else{
            return { false, 0, 0, 0 };
        }
        
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return res;
    }
};