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
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
   TreeNode* build(vector<int>& pre, vector<int>& in, int& rootIdx, int st, int end){
       if(st>end)return NULL;
       int pivot = st;
       while(in[pivot]!=pre[rootIdx])pivot++;
       rootIdx++;
       
       TreeNode* newNode = new TreeNode(in[pivot]);
       
      newNode->left = build(pre, in, rootIdx, st, pivot-1);
      newNode->right = build(pre, in, rootIdx, pivot+1, end);
       return newNode;
       
       
   }
};