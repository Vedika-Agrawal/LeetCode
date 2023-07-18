class LRUCache {
public:
    class node {
        public :
        int key;
        int val ;
        node* prev ;
        node* next;
        node(int key_, int val_){
            key = key_;
            val = val_;
        }
    };
    
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);
    int cap  ;
    
    
    unordered_map<int, node*>mp;
    
    void addNode(node* newNode){
        node* temp = tail->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = tail;
        tail->prev = newNode;
    }
    
    void deleteNode(node* delnode){
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int keyy) {
        if(!mp.count(keyy))return -1;
        node* temp = mp[keyy];
        int value = temp->val;
        deleteNode(temp);
        addNode(temp);
        mp.erase(keyy);  
        mp[keyy]= temp;
        return value;
    }
    
    void put(int keyy, int value) {
        if(mp.count(keyy)){
            node* temp = mp[keyy];
            deleteNode(temp);
            mp.erase(keyy);
        }
        if(mp.size()>=cap){
            mp.erase(head->next->key);
            deleteNode(head->next);
        }
        node* temp = new node(keyy, value);
        addNode(temp);
        mp[keyy] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */