class Solution {
public:
string reverseWords(string s) {
int n=s.size();
reverse(s.begin(),s.end());
int i=0,j=0,k=0;
while(j<n){
while(j<n && s[j]==' '){
j++;
}
if(i!=0 && j<n){
s[i]=' ';
i++;
}
k=i;
while(j<n && s[j]!=' '){
s[i++]=s[j++];
}
reverse(s.begin()+k,s.begin()+i);
}
s.resize(i);
return s;
}
};