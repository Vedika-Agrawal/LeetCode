class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxD = 0;
        int leftVal = 0;
        fBLVHelper(root, 1, maxD, leftVal);
        return leftVal;
    }
    
    void fBLVHelper(TreeNode* root, int depth, int& maxD, int& leftVal) {
        if (!root) return;
        
        if (depth > maxD) {
            maxD = depth;
            leftVal = root->val;
        }
        
        fBLVHelper(root->left, depth + 1, maxD, leftVal);
        fBLVHelper(root->right, depth + 1, maxD, leftVal);
    }
};
