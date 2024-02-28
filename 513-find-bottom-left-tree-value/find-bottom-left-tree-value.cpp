class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftmostValue = 0;
        findBottomLeftValueHelper(root, 1, maxDepth, leftmostValue);
        return leftmostValue;
    }
    
    void findBottomLeftValueHelper(TreeNode* root, int depth, int& maxDepth, int& leftmostValue) {
        if (!root) return;
        
        if (depth > maxDepth) {
            maxDepth = depth;
            leftmostValue = root->val;
        }
        
        findBottomLeftValueHelper(root->left, depth + 1, maxDepth, leftmostValue);
        findBottomLeftValueHelper(root->right, depth + 1, maxDepth, leftmostValue);
    }
};