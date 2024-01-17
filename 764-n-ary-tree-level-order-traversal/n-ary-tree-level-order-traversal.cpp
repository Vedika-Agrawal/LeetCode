/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            vector<int>temp;
            while(sz--){
                Node * it = q.front();
                q.pop();

                temp.push_back(it->val);
                for(auto node: it->children){
                    q.push(node);
                }
            }
            // reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};