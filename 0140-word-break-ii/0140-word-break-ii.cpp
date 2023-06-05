class Solution {
public:
    
     vector<string>ans, temp_res;
    
    void solve(string &s,unordered_set<string> &mp){
    if(s.size()==0){
        string k = "";
        for(auto it: temp_res){
            k+= it;
            k+=' ';
    
        }
        k.pop_back();
        ans.push_back(k);
        return ;
    }
    
    for(int i=0;i<s.size();i++){
        string temp = s.substr(0,i+1);
        if(mp.find(temp)!=mp.end()){
            
          temp_res .push_back(temp);
            
            string rest = s.substr(i+1);
            solve(rest,mp);
            temp_res.pop_back();
            
        }
    }
    
}
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        
        solve(s, st);
        return ans;
    }
};