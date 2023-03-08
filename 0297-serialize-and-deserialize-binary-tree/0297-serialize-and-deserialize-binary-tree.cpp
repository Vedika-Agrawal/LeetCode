/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string ans = "";
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL)ans.append("#,");
            else ans.append(to_string(node->val)+',');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s (data);
        
        string str ; 
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* node= q.front();
            q.pop();
            
            
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }else{
                TreeNode* l = new TreeNode (stoi(str));
                node->left = l;
                q.push(l);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }else{
                TreeNode* r = new TreeNode (stoi(str));
                node->right = r;
                q.push(r);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));