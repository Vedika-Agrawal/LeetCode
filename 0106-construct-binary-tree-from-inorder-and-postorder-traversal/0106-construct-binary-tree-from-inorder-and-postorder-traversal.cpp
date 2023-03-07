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
          int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }
    TreeNode* build(vector<int>& in, vector<int>& po, int st, int iend, int& postIdx) {
        if(st>iend)return NULL;
        TreeNode * root = new TreeNode (po[postIdx--]);
         int idx = find(begin(in), end(in), root -> val) - begin(in);
        root->right = build(in,po, idx+1, iend, postIdx);
        root->left = build(in , po, st, idx-1,postIdx);
        return root;
        
    }
};