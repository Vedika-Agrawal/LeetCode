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
    vector<TreeNode*> solve(int st, int end){
        vector<TreeNode*>ans;
         if(st>end){
            ans.push_back(NULL);
            return ans;
        }
        if(st==end){
            TreeNode* root  = new TreeNode(st);
            ans.push_back(root);
            return ans;
        }
        
        
        
        for(int i=st;i<=end;i++){
            vector<TreeNode*>left = solve(st, i-1);
            vector<TreeNode*>right = solve(i+1,end);
            
            for(auto l : left){
                for(auto r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
       
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};