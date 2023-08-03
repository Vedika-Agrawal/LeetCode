class Solution {
public:
 const vector<string> val= { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    
    
    vector<string> solve(string str){
          if(str.size()==0)return {""};
            string s = val[str[0]-'0'];
        
            string rem = str.substr(1);
            vector<string>temp = solve(rem);
            vector<string>res ;
            for(int i=0;i<s.size();i++){
                char ch = s[i];
                for(auto it:temp){
                    res.push_back(ch+it);
                }
            }
            return res;
    }
    
    vector<string> letterCombinations(string str) {
    
        if(str==""){
            return {};
        }
      return solve(str);
    }
};