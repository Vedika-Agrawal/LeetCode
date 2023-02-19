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
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(q.size()>0){
              int size = q.size();
            vector<int>raw(size);
          
            for(int i=0;i<size;i++){
                root = q.front();
                q.pop();
                int idx = (flag)?i:(size-1-i);
                raw[idx]=root->val;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            flag=!flag;
            ans.push_back(raw);
            
        }
        return ans;
        
    }
};