class Solution {
public:
    string convert(string s, int n) {
        if(n==1)return  s;
        string res= "";
        int jump = (n-1)*2;
        for(int i=0;i<n;i++){
            for(int j=i;j<s.size();j+=jump){
                res+=s[j];
                if(i>0 && i<n-1 && (j+jump-2*i)<s.size()){
                    res+=s[j+jump-2*i];
                }
            }
        }
        return res;
    }
};