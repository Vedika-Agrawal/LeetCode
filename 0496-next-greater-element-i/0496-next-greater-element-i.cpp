class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
       // vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        stack<int>st;
        st.push(-1);
        for(int i=n2.size()-1; i>=0;i--){
            int curr = n2[i];
            while(st.size() && st.top()<=curr){
                st.pop();
            }
            if(st.size()==0){
               mp[curr]=-1; 
                
            }
            else{
               mp[curr]=st.top();

            }
            st.push(curr);
            
        }
        
        vector<int>ans;
        for(auto it: n1){
            ans.push_back(mp[it]);
        }
        return ans;
        
    }
};