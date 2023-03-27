class Solution {
public:
    int ladderLength(string begin, string end, vector<string>&list) {
        queue<pair<string,int>>q;
        q.push({begin,1});
        unordered_set<string>st(list.begin(),list.end());
        st.erase(begin);
        while(!q.empty()){
            string word = q.front().first;
            int stp = q.front().second;
            q.pop();
            if(word==end)return stp;
            
            for(int i=0;i<word.size();i++){
                char ori = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i]=ch;
                   if( st.find(word)!=st.end()){
                       st.erase(word);
                       q.push({word,stp+1});
                   }
                }
                word[i]= ori;
            }
        }
        return 0;
    }
};