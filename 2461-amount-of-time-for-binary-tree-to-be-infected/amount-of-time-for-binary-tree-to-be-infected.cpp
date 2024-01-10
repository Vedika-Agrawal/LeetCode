
class Solution {
    
public:

    unordered_map<int,vector<int>>adj;
 
    void displayAdj(){
        for(auto it: adj){
            cout<< it.first<< " ";
            cout<<it.second.size();
            cout<<endl;
        }
    }
    void adjNodes(TreeNode* root){
        if (!root) return;

        int val = root->val;

        if (adj.find(val) == adj.end()) {
            // If the node is not in the adjacency list, add it
            adj[val];
        }

        if (root->left) {
            adj[val].push_back(root->left->val);
            adj[root->left->val].push_back(val);
            adjNodes(root->left);
        }

        if (root->right) {
            adj[val].push_back(root->right->val);
            adj[root->right->val].push_back(val);
            adjNodes(root->right);
        }
    }
    int solve (TreeNode* root, int st){
        queue<pair<int,int>>q;
        unordered_set<int>vis;
        vis.insert(st);
        q.push({st,0});
        int ans =0;
        while(q.size()){
            int ele = q.front().first;
            int level = q.front().second;
            q.pop();
            ans = level;

            for(auto it: adj[ele]){
                if(vis.count(it)==0){
                    q.push({it,level+1});
                    vis.insert(it);
                }
                
            }

        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        adjNodes(root);
        return solve(root, start);
    }
};