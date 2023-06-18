struct Node{
    Node* link[2];
    
    void put(int bit, Node* node){
        link[bit]= node;
    }
    
    Node* get(int bit){
        return link[bit];
    }
    
    bool contain(int bit){
        return link[bit];
    }
};

class Trie{
    private : 
    Node* root ;
    public :
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = num>>i & 1;
            if(!node->contain(bit)){
                node->put(bit, new Node());
            }
            node= node->get(bit);
        }
    }
    
    int maxXor(int num){
        Node *node = root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=num>>i & 1;
            if(node->contain(1-bit)){
                maxi= maxi | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
    
};



class Solution {
public:
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        Trie trie;
        
        sort(nums.begin(),nums.end());
        // for(auto it : nums){
        //     trie.insert(it);
        // }
        vector<int>ans(q.size());
        int maxi = INT_MIN;
        
        vector< pair<pair<int,int>,int>>v;
        for(int i=0;i<q.size();i++){
            v.push_back( {{ q[i][1] , q[i][0] }, i});
        }
        
        sort(v.begin(),v.end());
        int j  = 0;
        for(auto it: v){
            int range= it.first.first;
            int x = it.first.second;
            int idx = it.second;
            
            int maxi = INT_MIN;
            
            while(j<nums.size() && nums[j] <=range ){
                trie.insert(nums[j]);
                j++;
                // maxi = max(maxi, trie.maxXor(x));
                // j++;
            }
             if(j==0){
                ans[idx]=-1;
            }
            else{
                int temp =trie.maxXor(x);
                ans[idx] = temp;
            }
            
        }
        
        return ans;
        
        
    }
};