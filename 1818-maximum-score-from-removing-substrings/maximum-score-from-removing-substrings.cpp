class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0 ;
        stack<char>st;
        int check = x>=y;// ab else ba.
        for(int i=0;i<s.size();i++){
            if(st.size() && (  (check && s[i]=='b' && st.top()=='a') || (!check &&s[i]=='a' && st.top()=='b')) ){
                points += max(x,y);
                st.pop();
            }
            else{
                st.push(s[i]);
            }

        }
        s = "";
        while(st.size()){
            s+=st.top();
            st.pop();
        }
        cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            if(st.size() && (  (check && s[i]=='b' && st.top()=='a') || (!check &&s[i]=='a' && st.top()=='b')) ){
                points += min(x,y);
                st.pop();
            }
            else{
                st.push(s[i]);
            }

        }
        return points;




    }
};