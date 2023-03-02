class Solution {
public:
    int compress(vector<char>& v) {
        int i =0,res=0 ;
       
        while(i<v.size()){
             int len = 1;
            while(i+len<v.size() && v[i]==v[i+len]){
                len++;
            }
            v[res++]=v[i];
            if(len>1){
                for(auto it: to_string(len)){
                    v[res++]=it;
                }
            }
            i+=len;
            
        }
        return res;
        
    }
};