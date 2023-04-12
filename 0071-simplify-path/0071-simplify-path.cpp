class Solution {
public:
    string simplifyPath(string path) {
        int idx = path.size()-1;
        string ans="";
        int back = 0 ;
         while(idx>=0){
             string temp = "";
             while(idx>=0 && path[idx]!='/'){
                 temp = path[idx]+temp;
                 idx--;
                 
             }
             idx--;
             if(temp=="" || temp==".")
                 continue;
             if(temp=="..")back++;
             else if(back>0){
                 back--;
             }
             else{
                 ans = temp +ans;
                 ans="/"+ans;
             }
                 
             
         }
        if(ans=="")return "/";
        return ans;
        
    }
};