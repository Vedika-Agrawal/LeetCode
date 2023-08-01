class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans= 0,flag  =0;
        set<char>st;
        for(; j<s.size();j++){
            
            if(st.count(s[j])==0){
                
                st.insert(s[j]);
            }
            else{
                while(st.count(s[j])!=0){
                   st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
            
            }
            cout<<j-i+1<<" ";
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};