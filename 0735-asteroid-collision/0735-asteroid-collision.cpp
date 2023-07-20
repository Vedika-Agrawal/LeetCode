class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>st;
        for(auto it: v){
            if(st.size()==0)st.push(it);
            else{
                while(st.size() && st.top()>0 && it<0 && st.top()<abs(it)){
                    st.pop();
                }
                if(st.size() && st.top()==abs(it) && st.top()>0 && it<0)st.pop();
                else if(st.size() &&st.top()>0 && it<0  &&  st.top()> abs(it)){
                    continue;
                }
                else{
                    st.push(it);
                }
            }
        }
        
        vector<int>ans;
        while(st.size()){
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
        
    }
};