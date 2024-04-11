class Solution {
public:
    vector<vector<string>> ans;
    int isPalindrome(string S) {
        int i=0;
        int j=S.length()-1;
        
        while(j>i){
            if(S[i]==S[j]){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        
        return 1;
    }
    void solve(string s, int st, vector<string>&v){
        if(st==s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i = st; i<s.size(); i++){
            string temp = s.substr(st, i-st+1);
            if(isPalindrome(temp)){
                v.push_back(temp);
                solve(s, i+1, v);
                v.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<string>v;
        int n = s.size();
        solve(s, 0, v);
        return ans;
    }
};