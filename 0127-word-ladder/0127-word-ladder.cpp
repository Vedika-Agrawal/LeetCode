class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& list) {
        unordered_set<string>st(list.begin(), list.end());
        st.erase(beg);
        queue<pair<string, int >>q;
        q.push({beg,1});
        while(q.size()){
            string s = q.front().first;
            int dis  = q.front().second;
            if(s==end)return dis;
            q.pop();
            for(int i=0;i<s.size();i++){
                char old  = s[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    s[i] = ch;
                    if(st.find(s)!=st.end()){
                        
                        q.push({s, dis+1});
                        st.erase(s);
                        
                    }
                    s[i]= old;
               
                }
            }
        }
        return  0;
    }
};