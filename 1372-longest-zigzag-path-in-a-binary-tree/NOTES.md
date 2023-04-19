/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
pair<int,char> solve(TreeNode* root){
if(!root)return {0,'r'};
auto left = solve(root->left);
auto right = solve(root->right);
pair<int,char>temp1, temp2;
if(left.second=='r') temp1 = {left.first+1, 'l'};
else {temp1 = {left.first, 'l'}; }
if(right.second=='l') temp2 = {right.first+1, 'r'};
else {temp2 = {right.first, 'l'}; }
return  temp1.first > temp2.first ?  temp1 : temp2;
}
int longestZigZag(TreeNode* root) {
auto it = solve(root);
return it.first;
}
};