class Solution {
public:
    
    bool check (char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ) return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int i=0,j = s.size()-1;
        while(i<j){
            if(check(s[i])==false){
                i++;
            }
            if(check(s[j])==false){
                j--;
            }
            
            if(check(s[i]) && check(s[j]))
              swap(s[i],s[j]), i++, j--;
            
            
            
        }
        return s;
    }
};
         