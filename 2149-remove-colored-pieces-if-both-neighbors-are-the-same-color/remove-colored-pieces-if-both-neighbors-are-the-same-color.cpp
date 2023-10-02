class Solution {
public:
    bool winnerOfGame(string v) {
       int a =0, b= 0;
       int n = v.size();
       for(int i=0;i<v.size();i++){
           if(i+1<n && i+2<n && v[i]==v[i+1] && v[i]==v[i+2]){
               if(v[i]=='A')a++;
               else b++;
           }
       } 
       return a>b;
    }
};