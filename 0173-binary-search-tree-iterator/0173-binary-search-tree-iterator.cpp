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
class BSTIterator {
public:
    TreeNode* head;
    stack<TreeNode*>st;
    
     void solve(TreeNode* root){

         if(root==NULL)return ;
            st.push(root);
            solve(root->left);
         
    }
    
    BSTIterator(TreeNode* root) {
       head= root; 
        solve(root);
    }
    
   
    
    
    int next() {
        auto it = st.top();
        st.pop();
        solve(it->right);
        return it->val;
    }
    
    bool hasNext() {
       return st.size(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */