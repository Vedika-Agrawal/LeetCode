class Solution {
public:
     int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int> m;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            m[s[j]]++;
            if(j-i+1==m.size()){
                ans=max(ans,(j-i+1));
            }
            else{
                while((j-i+1)>m.size()){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                if(j-i+1==m.size()){
                    ans=max(ans,(j-i+1));
                }
            }
            j++;
        }
        return ans;
    }
};