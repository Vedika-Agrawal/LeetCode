/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:


     unordered_map<Node*,Node*> mp;
     Node* dfs( Node* node){
        
        Node* clone  = new Node (node->val);
        mp[node] = clone;
         vector<Node*> temp;
        
        for(auto it : node->neighbors){
            
            if(mp.find(it)!=mp.end()){
                temp.push_back(mp[it]);
            }
            else{
                auto k = dfs(it);
                temp.push_back(k);
            }
        }
        
        clone->neighbors = temp;
        return clone;
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node);
    }
};