class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if(n>v.size())return false;
        
        int i=0;
        while(i<v.size()){
            int p = i-1, f = i+1; 
            if(v[i]==0){
                if(p>=0 && f<v.size()){
                    if(v[p]==0 && v[f]==0){
                        n--;
                        i++;
                    }
                }
                if(p==-1 && f==1 && v.size()==1){
                    return true;
                }
                    if(p==-1 && f<v.size() && v[f]==0){
                        n--;
                        i++;
                    }
                    if( f==v.size() && p>=0 && v[p]==0 ){
                        n--;
                        i++;
                    }
                
                    
                
            }
            i++;
        }
        
        return n<=0 ? true : false;
    }
};