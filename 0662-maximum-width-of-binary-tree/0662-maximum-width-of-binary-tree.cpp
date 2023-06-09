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
  #define ll long long  
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode* , int>>q;
        q.push({root,0});
        ll ans= INT_MIN;
        while(q.size()){
            int n = q.size();
             
            ll f = q.front().second;
            ll l = q.back().second;
             ans = max(ans, l-f+1);
           while(n--){
                TreeNode* node = q.front().first;
                ll idx = q.front().second;
                 q.pop();
               


                if(node->left){
                    q.push({node->left, idx*2 +1});
                }
                 if(node->right){
                    q.push({node->right, idx*2 +2});
                }
           }
        }
        return ans;
    }
};