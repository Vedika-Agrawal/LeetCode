class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0;
        int i=0,j=0;
        int cnt = 0 ;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==t.size()){
            ans =0 ;
        }
        else {
            ans = t.size()-j;
        }
        return ans;
    }
};