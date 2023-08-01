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
    struct check{
        bool isBst ;
        int mn ;
        int mx;
        int sum ;
    };
    
    int ans  = 0 ;
    
    check solve(TreeNode* root){
        if(!root){
            return {true, INT_MAX, INT_MIN, 0};
        }
        
        check l = solve(root->left);
        check r = solve(root->right);
        if(l.isBst && r.isBst && l.mx < root->val && r.mn > root->val ){
            int total = l.sum + r.sum+root->val;
            ans = max(ans,total);
            return {true, min(l.mn,root->val), max(root->val,r.mx), total };
        }
        return {false, 0,0,0};
        
        
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        
        return ans;
    }
};