/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        vector<int>ans;
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*, int>visited;
        
         queue<TreeNode*>q;
        q.push(root);
         while(q.size()>0){
            TreeNode* curr = q.front(); q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        
        // queue<TreeNode*>q;
        
        q.push(tar);
        
        visited[tar]=true;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto it = q.front(); q.pop();
                if(k==0){
                    ans.push_back(it->val);
                }
                if(it->left && !visited[it->left]){
                    visited[it->left]= true;
                    q.push(it->left);
                }
                if(it->right && !visited[it->right]){
                    visited[it->right]= true;
                    q.push(it->right);
                }
                if(parent[it] && !visited[parent[it]]){
                    visited[parent[it]]=true;
                    q.push(parent[it]);
                }
            }
            k--;
        }
        return ans;
    }
};