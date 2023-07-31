class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string temp = "";
        vector<string>k;
        while(getline(st,temp, ' ')){
            if(temp.size()>0){
                k.push_back(temp);
            }
        }
        reverse(k.begin(),k.end());
        string ans = k[0];
        for(int i=1;i<k.size();i++){
            string it = k[i];
            ans+=' ';
            ans+= it;
            
        }
        return ans;
    }
};