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
    vector<int>levelSum;
    
    void levelOrder(TreeNode* root){
        if(!root)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            while(sz--){
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            levelSum.push_back(sum);
        }
        
    }
    
    void solve(TreeNode* root, int sib, int level){
        if(!root)return;
        
        int leftChild = root->left ? root->left->val : 0;
        int rightChild = root->right ? root->right->val : 0;
        
       
         solve(root->left, rightChild, level+1);
         solve(root->right, leftChild, level+1);
        
        root->val = levelSum[level] - root->val - sib;
        
        
        
        
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        levelOrder(root);
        solve(root,0,0);
        return root;
    }
};