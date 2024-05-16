class Solution {
public:
    bool solve(TreeNode* root){
        if(!root) return true;
        if(!root->left && !root->right) return root->val;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(root->val == 3 && (l == true && r == true)){
            return true;
        }
        else if(root->val == 3 && (l == false || r == false)){
            return false;
        }
        else if(root->val == 2 && (l == true || r == true)){
            return true;
        }
        else {
            return false;
        }
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};
