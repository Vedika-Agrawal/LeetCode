class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>v(26,0);
        int ans = -1;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']!=0){
                ans = max(ans, i - v[s[i]-'a']);
            }
            else{
                v[s[i]-'a']=i+1;
            }
            
        }
        return ans;
    }
};