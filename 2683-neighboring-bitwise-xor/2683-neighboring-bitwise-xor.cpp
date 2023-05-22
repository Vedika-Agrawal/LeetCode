class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
        int st= 0 ;
        int next = 0;
        
        for(int i=0;i<der.size()-1;i++){
            if(der[i]==1){
                next ==0 ? next=1 :next=0;
            }
           
        }
        int n = der.size();
        
        if(der[n-1]==0 ){
            return next==st ?  true:false;
        }
        else{
            return next!=st ? true:false;
        }
        
       
    }
};