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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)return true;
        int level = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            int prev = -1;
            while(sz--){
                auto node = q.front(); 
                q.pop();
                if(prev!=-1 && level%2!=0 && node->val <= prev || (node->val%2==0 && level%2!=0)) return false;
                if(prev!=-1 && level%2==0 && node->val >= prev ||( node->val%2!=0 && level%2==0)) return false;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                prev = node->val;
            }
            level ++;
        }
        return true;
    }
};