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
    TreeNode* deleteNode(TreeNode* root, int key) {
         if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode *dummy = root;
        
        
        while(root!=NULL){
            if(root->val > key){
               if(root->left && root->left->val == key){
                   root->left = helper(root->left);
                   break;
                   
               } 
                else{
                    root= root->left;
                }
            }
            else{
               
               if(root->right && root->right->val == key){
                   root->right = helper(root->right);
                   break;
               } 
                else{
                    root= root->right;
                }
            
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(!root)return NULL;
        if(!root->right)return root->left;
        if(!root->left)return root->right;
        TreeNode* curr_right = root->right;
        TreeNode* lst_right = findLastRight(root->left);
        lst_right->right = curr_right;
        return root->left;
    }
    // TreeNode* findLastRight(TreeNode* node){
    //     if(node->right)findLastRight(node->right);
    //     return node;
    // }
     TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};