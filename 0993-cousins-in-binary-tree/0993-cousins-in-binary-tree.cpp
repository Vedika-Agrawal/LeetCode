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
    
    int depthX, depthY,parentX, parentY;
    
    void depth(int x, int y, int dep, TreeNode* root, int par){
        if(!root)return ;
        if(root->val==x){
            depthX = dep;
            parentX = par;
        }
        if(root->val==y){
            depthY = dep;
            parentY = par;
        }
        
        depth(x,y,dep+1,root->left , root->val);
         depth(x,y,dep+1,root->right,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)return false;
        depth(x,y,0,root,-1);
        
        if((depthX == depthY) && (parentX !=parentY))return true;
        return false;
    }
};