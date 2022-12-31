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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
          return ans;
        }  
        stack<TreeNode*>st;
        st.push(root);
        while(st.size()>0){
            root = st.top();
            ans.push_back(root->val);
            st.pop();
            if(root->right!=nullptr){
                st.push(root->right);
            }
            if(root->left!=nullptr){
                st.push(root->left);
            }
            
        }
        return ans;
    }
};