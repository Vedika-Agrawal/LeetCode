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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        bool ltr =  true;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            vector<int>v(sz);
            for(int i=0;i<sz;i++){
                TreeNode* temp = q.front();
                q.pop();
                int idx = ltr ? i : sz-i-1;
                v[idx] = temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
               
               
                
                
            }             
            ltr= !ltr;

             ans.push_back(v);
        }
        return ans;
    }
};