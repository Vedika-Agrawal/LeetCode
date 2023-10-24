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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL)return ans;
        q.push(root);
        
        while(q.size()){
            int sz = q.size();
            int mx = INT_MIN;
            while(sz--){
               TreeNode* node =q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
                mx = max(mx, node->val);
            }
            ans.push_back(mx);

        }
        return ans;
    }
};