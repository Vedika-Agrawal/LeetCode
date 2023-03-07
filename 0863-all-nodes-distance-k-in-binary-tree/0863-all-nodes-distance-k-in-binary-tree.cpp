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
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*, int>visited;
        queue<TreeNode*>q;
        q.push(root);
        
        // parent set 
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
        
        q.push(t);
        visited[t]=true;
        int curr_level = 0;
        while(q.size()>0){
            if(curr_level++==k)break;
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front(); q.pop();
                // left 
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                // right
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                // parent
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }
        
        vector<int>ans;
        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};