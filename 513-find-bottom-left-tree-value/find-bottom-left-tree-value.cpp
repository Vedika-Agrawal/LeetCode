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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        int ans = root->val;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            bool first = 0;
            while(sz--){
                auto node = q.front();
                if(first==0) ans = node->val, first = 1;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};