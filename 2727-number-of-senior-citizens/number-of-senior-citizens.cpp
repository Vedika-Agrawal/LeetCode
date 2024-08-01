class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto it: details){
            char ch = it[11];
            char ch1 = it[12];
            
            string s = "";
            s+=ch;
            s+=ch1;
            int a = stoi(s);
            if(a>60)cnt++;
            
        }
        return cnt;
    }
};