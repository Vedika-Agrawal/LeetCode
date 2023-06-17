void insert(int num){
Node* node=root;
for(int i=31;i>=0;i--){
int bit=(num>>i) & 1;
if(!node->contains(bit)){
node->put(bit,new Node());
}
node=node->get(bit);
}
}
int maxSum(int num){
Node* node=root;
int maxi=0;
for(int i=31;i>=0;i--){
int bit=(num>>i) & 1;
if(node->contains(1-bit)){
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
​
class Solution {
public:
int findMaximumXOR(vector<int>& nums) {
int ans=0;
Trie trie;
for(auto it:nums){
trie.insert(it);
}
for(auto it:nums){
ans=max(ans,trie.maxSum(it));
}
return ans;
}
};