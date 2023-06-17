struct Node{
    Node * link[26];
    bool flag = false;
    
    bool contain(char ch){
        return link[ch-'a']!=  NULL;
    }
    
    void put(char ch, Node* node){
        link[ch-'a']= node;
    }
    
    Node* get(char ch){
        return link[ch-'a'];
    }
    
   
};


class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contain(word[i])){
                node->put(word[i], new Node());
                
            }
           node =  node->get(word[i]);
            
        }
        
        node->flag = true;
        
    }
    
    bool search(string word) {
        
        Node* node  = root;
        for(auto it: word){
            if(!node->contain(it)){
                return false;
            }
            node = node->get(it);
        }
       return  node->flag ? true : false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto it : prefix){
            if(!node->contain(it))return false;
            node = node->get(it);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */