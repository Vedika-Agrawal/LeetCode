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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode* ,  pair<int,int> >>q;
        map<int, map<int, multiset<int>  >  >mp;
        
        
        
        
        if(!root)return ans;
        q.push({root, {0,0}});
        while(q.size()){
           auto it=q.front();

            q.pop();
            TreeNode* temp = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            mp[col][row].insert( temp->val);
            
            if(temp->left){
                q.push({temp->left, {row+1, col-1} });
            }
            if(temp->right){
                q.push({temp->right, {row+1, col+1} });
            }
            
            
        }
        
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                for(int j : i.second)
                 temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};