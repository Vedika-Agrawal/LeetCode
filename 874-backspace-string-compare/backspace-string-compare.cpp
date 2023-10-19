class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        string ans1="";
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            // cout<<ch<<endl;
            if(ch=='#' ){
                if(st.size()>0)
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
        while(st.size()>0){
            char ch = st.top();
            // cout<<ch<<endl;
            st.pop();
            ans1+=ch;
            // cout<<ans1<<endl;
        }
        
        string ans2="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='#'){
                 if(st.size()>0)
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        while(st.size()>0){
            char ch = st.top();
            st.pop();
            ans2+=ch;
        }
        cout<<ans1<<endl<<ans2;
        if(ans1==ans2)return true;
        else return false;
    }
};