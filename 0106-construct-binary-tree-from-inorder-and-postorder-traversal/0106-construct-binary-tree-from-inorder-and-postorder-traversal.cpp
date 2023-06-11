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
    
    TreeNode* solve(vector<int>& in, vector<int>& post, int &idx, int st, int end){
        if(st>end)return NULL;
        TreeNode* node  = new TreeNode(post[idx]);
        int temp = find(in.begin(), in.end(), node->val)-in.begin();
        idx--;
         node->right = solve(in, post, idx, temp+1, end);
        node->left  = solve(in, post, idx, st, temp-1);
       
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size()-1;
        return solve(in,post, n, 0,n);
    }
};

