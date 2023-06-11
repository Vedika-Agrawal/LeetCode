/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };&
 */
class Solution {
public:
   TreeNode* solve(vector<int>& pre, vector<int>& ino, int& idx, int st, int end){
        if(st>end)return NULL;
       int temp = st;
       while(ino[temp]!=pre[idx])temp++;
       idx++;
         
         TreeNode* newNode = new TreeNode(ino[temp]);
       
      newNode->left = solve(pre, ino, idx, st, temp-1);
      newNode->right = solve(pre, ino, idx, temp+1, end);
       return newNode;
       
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        int rootIdx = 0;
        return solve(pre, ino, rootIdx, 0, ino.size()-1);
    }
};