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
//     int cnt = 0 ;
//     int ans = INT_MIN;
//     void solve(TreeNode* root, int k){
//         if(root==NULL)return ;
       
//         solve(root->left, k);
//         cnt++;
//         if(k==cnt)
//         ans = root->val;

        
//         solve(root->right,k);
           
           
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         solve(root, k);
//         return ans;
//     }
    int ans;
    void solve(TreeNode* root,int k,int &i){
        if(!root){
            return;
        }
        solve(root->left,k,i);
        i++;
        if(i==k){
            ans=root->val;
            // return;
        }
        
        solve(root->right,k,i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        solve(root,k,i);
        return ans;
    }
};