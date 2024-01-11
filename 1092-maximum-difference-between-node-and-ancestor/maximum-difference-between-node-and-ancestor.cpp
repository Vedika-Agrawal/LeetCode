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
    int ans = 0;
    int smallest(TreeNode* root){
        if(!root)return 1e5+1;
        int l  = 1e5+1, r = 1e5+1;
        if(root->left){
            l = min(root->left->val, smallest(root->left));
        }
        if(root->right){
            r = min(root->right->val, smallest(root->right));
        }
        return min(l,r);

    }

    int greatest(TreeNode* root){
        if(!root)return -1;
        int l  = -1, r = -1;
        if(root->left){
            l = max(root->left->val, greatest(root->left));
        }
        if(root->right){
            r = max(root->right->val, greatest(root->right));
        }
        return max(l,r);

    }
    
    void dfs(TreeNode* root){
        if(!root)return ;
        int mn = smallest(root);
        int mx = greatest(root);
        // ans = max{ans, abs(mn-root->val), abs(mx-root->val)};
        if(mn!=1e5+1)
        ans = max(ans, abs(mn - root->val));
        if(mx!=-1)
        ans = max(ans, abs(mx - root->val));
        dfs(root->left);
        dfs(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};