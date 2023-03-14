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
     int total =0;
    
    int sumNumbers(TreeNode* root) {
        
        solve(root, 0);
        return total;
    }
   
    void solve(TreeNode* root, int ans){ // 4, 0 // 
        if(!root)
        {
            return;
        }
        ans = ans * 10 + root->val; // 4 // 49 // 495
        
         if (root->left == NULL && root->right == NULL) {
            total +=ans;
             
            return;
        }
        solve(root->left, ans); // 9, 4 // 9, 49 // 
        solve(root->right, ans);
    }
};