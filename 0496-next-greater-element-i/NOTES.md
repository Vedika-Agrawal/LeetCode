class Solution {
public:
vector<int> nextGreaterElement(vector<int>& arr, vector<int>& brr) {
stack<int>st;
unordered_map<int,int>mp;
for(int i=0;i<brr.size();i++){
char ch = brr[i];
while(st.size() && st.top()<ch){
mp[st.top()]= ch;
st.pop();
}
st.push(brr[i]);
}
vector<int>ans;
for(auto it : arr){
ans.push_back(mp.count(it) ? mp[it] :-1);
}
return ans;
}
};