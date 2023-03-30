class Solution {
public:
    unordered_map<string,bool> mp;          
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())         
            return false;
        if(s1.size()==0 && s2.size()==0)   
            return true;
        if(s1.compare(s2)==0)               
            return true;
        if(s1.size()<=1)                    
            return false;
        
        string key=s1;                      
        key.push_back(' ');
        key.append(s2);
        if(mp.find(key) != mp.end())        
            return mp[key];
       
        int n=s1.size();
        bool flag=false;
        for(int i=1;i<n;i++) {
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i))==true
              && isScramble(s1.substr(i,n-i),s2.substr(0,n-i))==true)
                                      || 
               (isScramble(s1.substr(0,i),s2.substr(0,i))==true
                && isScramble(s1.substr(i,n-i),s2.substr(i,n-i))==true)) {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
};