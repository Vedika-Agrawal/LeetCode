class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<int>st;
        for(int i=0;i<token.size();i++){
            if(token[i]!="+"&& token[i]!="*" && token[i]!="/" && token[i]!="-"){
              st.push(stoi(token[i]));
            }
            else{
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                string ch = token[i];
                if(ch=="+"){
                    st.push(a+b);
                }
                else if(ch=="-"){
                    st.push(b-a);
                }
                else if(ch=="*"){
                    st.push(b*a);
                }
                else{
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};