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
    int rangeSumBST(TreeNode* root, int low, int right) {
        if(!root)return 0;
        if(root->val< low){
            // root =root->right;
            return rangeSumBST(root->right,low,right);
        }
        else if(root->val>right){
            return rangeSumBST(root-> left,low,right);
        } 
        cout<<root->val<<endl;
        return root->val +  rangeSumBST(root->right,low,right) + rangeSumBST(root->left,low,right);
    }
};


