class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j = 0 ; // poped
        for(auto it: pushed){
            st.push(it);
            while(j<popped.size() && st.size()>0 &&  popped[j]==st.top())
            {
                st.pop();
                j++;
            }
        }
        
        if(st.size()==0)return true;
        return false;
        
        
    }
};