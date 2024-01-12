class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1  = 0;
        int cnt2 =  0;
        for(int i=0;i<s.size();i++){
            int it = s[i];
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U'){
                if(i < s.length()/2) cnt1++;
                else cnt2++;
            }
        }
        return cnt1 == cnt2 ? true : false;
    }
};

