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
    void solve(Node*root, vector<int>&ans){
        stack<Node*>st;
        st.push(root);
        while(st.size()){
            auto it = st.top();
            st.pop();
            ans.push_back(it->val);
            int sz = it->children.size();
            for(int i= sz-1; i>=0;i--){
                st.push(it->children[i]);
            }

        }
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(!root)return ans;
        solve(root,ans);
        return ans;
    }
};