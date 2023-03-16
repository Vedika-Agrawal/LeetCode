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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int curr = n-1;
        
        return solve(inorder, postorder, 0, n-1, curr);
    }
    
    TreeNode* solve(vector<int>& in, vector<int>& po, int st, int end, int &curr_pos ){
        if(st>end)return NULL;
        TreeNode* root = new TreeNode(po[curr_pos--]);
        int idx = find(in.begin(), in.end(), root->val)-in.begin();
        root->right = solve(in,po,idx+1,end,curr_pos);
        root->left = solve(in,po,st,idx-1,curr_pos);
        return root;
    }
};