class Solution {
public:
    int n;
    
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;
        
        while(j>i){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    vector<vector<string>>ans;
    
    void solve(string& s,  vector<string>&temp){
        
        if(s.size()==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i< s.size(); i++){
            
             string str = s.substr(0, i+1);
            string rem = s.substr(i+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(rem,temp);
                temp.pop_back();
            }
            
            
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string>temp;
        solve(s, temp );
        return ans;
    }
};