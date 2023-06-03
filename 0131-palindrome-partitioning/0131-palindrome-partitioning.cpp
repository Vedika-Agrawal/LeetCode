class Solution {
public:
    vector<vector<string>>ans; 
    int n ;
    
    int isPalindrome(string S)
    {
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
    
    void solve(string s, vector<string>temp){
        
        if(s.size()==0){
            ans.push_back(temp);
            return ;
        }
        
         for(int i=0;i<s.size();i++){
            string check = s.substr(0,i+1);
            string rem = s.substr(i+1);
            
            if(isPalindrome(check)){
                temp.push_back(check);
                solve(rem,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string>temp;
        solve(s,temp);
       
        return ans;
        
    }
};