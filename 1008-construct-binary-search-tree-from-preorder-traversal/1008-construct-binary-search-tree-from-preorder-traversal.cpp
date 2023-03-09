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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return built(preorder,i, INT_MAX);
    }
    TreeNode* built(vector<int>&v , int &i, int bound){
        if(i==v.size() || v[i] > bound)return NULL;
        TreeNode* root = new TreeNode(v[i++]);
        
        root->left = built(v, i, root->val);
        root->right = built(v, i, bound);
        return root;
    }
};