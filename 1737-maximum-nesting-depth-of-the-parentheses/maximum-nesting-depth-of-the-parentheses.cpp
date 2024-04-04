class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        stack<char> st;
        for(auto it: s){
            if(it=='(')st.push('(');
            int ele = st.size();
            cnt = max(cnt, ele);
            if(it==')')st.pop();
        }
        return cnt;
    }
};