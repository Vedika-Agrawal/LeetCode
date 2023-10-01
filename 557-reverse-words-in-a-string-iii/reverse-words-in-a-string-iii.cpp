class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream st(s) ;
        string temp = "";
         while(getline(st,temp, ' ')){
             if(temp.size()>0){
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    ans+=" ";
                }
         }
         ans.pop_back();
        return ans;
    }
};
