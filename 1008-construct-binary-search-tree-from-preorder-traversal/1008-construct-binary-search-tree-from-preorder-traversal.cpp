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
    TreeNode* solve(vector<int>&pre, int &st, int &end){
        if(st>=pre.size() || pre[st]>end)return NULL;
        TreeNode* root = new TreeNode(pre[st]);
        st++;
        root->left = solve(pre, st,root->val );
        root->right = solve(pre, st, end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i = 0;
        int j = INT_MAX;
        return solve(pre,i,j);
    }
};
