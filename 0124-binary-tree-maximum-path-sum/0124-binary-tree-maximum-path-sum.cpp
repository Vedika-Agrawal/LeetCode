class Solution {
public:
    int ans=-10000000;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        // if(!root->left && !root->right){
        //     return root->val;
        // }
        int left=max(0,solve(root->left));
        int right=max(0,solve(root->right));
        
        int x=max({root->val,root->val+left,root->val+right});
        int temp = left+right+root->val;
        ans=max(ans,temp);
        return x;
        // return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }
        solve(root);
        return ans;
    }
};