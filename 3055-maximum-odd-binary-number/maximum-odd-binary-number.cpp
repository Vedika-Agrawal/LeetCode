class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for(auto it: s) one += it=='1' ? 1 : 0;
        int n = s.size();
        s[n-1] ='1';
        one--;
        int i = 0;
        for(int i=0;i<n-1;i++){
            if(one>0){
                s[i]='1';
                one--;
            }
            else s[i]='0';
        }
        return s;
    }
};