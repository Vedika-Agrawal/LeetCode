class Solution {
public:
    bool isStretchy(string s, string t){
       int n = s.size(), m = t.size(), j = 0;
       for(int i = 0; i<n;i++){
           if(j<m && s[i]==t[j])j++;
           else if(i>1 && s[i-2]==s[i-1] && s[i-1]==s[i]);
           else if(0<i && i< n-1 && s[i-1]==s[i] && s[i]== s[i+1]);
           else return false;
           
       }
       return j==m;
    }
    int expressiveWords(string s, vector<string>& words) {
        int cnt = 0;
        for(auto it: words){
            if(isStretchy(s, it)) cnt++;
        }
        return cnt;
    }
};