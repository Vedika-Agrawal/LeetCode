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
    int data =0;
    int curr = 0;
    int mx =0 ;
    vector<int>ans;
    void dfs(TreeNode* root){
        if(!root)return;

        dfs(root->left);

        // main task =============
        if(root->val != data){
            data = root->val;
            curr = 1;
        }
        else{
            curr++;
        }
        if(curr>mx){
            vector<int>nw;
            ans = nw;
            mx = curr;
        }

        if(mx== curr){
            ans.push_back(data);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};