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
    TreeNode* solve(vector<int>& pre, int &st, int range){
        if(st>=pre.size()  || pre[st]>range)return NULL;
        TreeNode* root = new TreeNode(pre[st]);
        // int idx  = *upper_bound(pre.begin(),pre.end(), pre[st]);
        st++;
        root->left = solve(pre, st, root->val);
        
        root->right = solve(pre, st , range);
        
        return root;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        int idx = 0;
        return solve(pre, idx, INT_MAX);
    }
};