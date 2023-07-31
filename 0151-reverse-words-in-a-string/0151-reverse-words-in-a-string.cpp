class Solution {
public:
    string reverseWords(string s) {
        // s+=' ';
        int i=0 , k = 0,j=0;
        reverse(s.begin(),s.end());
        int n = s.size();
        while(i<n){
            while(i<n && s[i]==' ')i++;
            // j = i;
            // int pp = k;
            // while(j<n && s[j]!=' ')j++;
             if(j!=0 && i<n){
                s[j]=' ';
                j++; 
            } 
            int pp = j;
            while(i<n && s[i]!=' '){
                s[j++]= s[i++];
                // k++;
                // i++;
            }
            
            reverse(s.begin()+pp , s.begin()+j);
            //  if(i<n){
            //     s[k]=' ';
            //     k++; 
            // } 
           
        }
        s.resize(j);
        // cout<<s<<endl;
        return s;
    }
};