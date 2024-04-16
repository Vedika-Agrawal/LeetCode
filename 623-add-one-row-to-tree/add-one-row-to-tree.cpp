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
    TreeNode* createNode(int val){
        return new TreeNode(val);
    }
    void solve(TreeNode* root, int val, int depth){
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});

        while(q.size()){
            cout<<q.size()<<endl;
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level+1==depth){
                TreeNode* leftNode= createNode(val);
                TreeNode* rightNode = createNode(val);
                leftNode->right= NULL;
                rightNode->left = NULL;
                leftNode->left= node->left;
                rightNode->right = node->right;
                node->left = leftNode;
                node->right = rightNode;
            }
            else{
                if(node->left)q.push({node->left, level+1});
                if(node->right)q.push({node->right, level+1});
            }
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = createNode(val);
            node->left = root;
            node->right = NULL;
            return node;
        }
        solve(root, val, depth);
        return root;
    }
};