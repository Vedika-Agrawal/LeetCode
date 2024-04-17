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
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";
    void dfs(TreeNode* root, string s){
        if(!root) return ;
         s += root->val + 'a';
        if(!root->left && !root->right){
           
            reverse(s.begin(),s.end());
            ans = min(ans, s);
            cout<<ans<<endl;
            // return ;
        }
        
        dfs(root->left, s);
        dfs(root->right, s);
        s.pop_back();
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return ans;
    }
};