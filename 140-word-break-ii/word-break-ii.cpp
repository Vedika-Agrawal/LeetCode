class Solution {
public:
    vector<string>ans;
    set<string>st;
    void solve(string &s, vector<string>&temp){
        if(s.size()==0){
            string res  = temp[0];
            for(int i=1;i<temp.size();i++){
                res+=" ";
                res+= temp[i];
            }
            ans.push_back(res);
            return ;
        }
        for(int i=0;i<s.size();i++){
            string str = s.substr(0, i+1);
            string rem = s.substr(i+1);
            if(st.count(str)!=0){
                temp.push_back(str);
                solve(rem,temp);
                temp.pop_back();
                
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        st.insert(word.begin(), word.end());
        vector<string>temp;
        solve(s,temp);
        return ans;
    }
};