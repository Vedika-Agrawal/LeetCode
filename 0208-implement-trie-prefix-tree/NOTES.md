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
​
​
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
node->get(word[i]);
}
node->flag = true;
}
bool search(string word) {
Node* node  = root;