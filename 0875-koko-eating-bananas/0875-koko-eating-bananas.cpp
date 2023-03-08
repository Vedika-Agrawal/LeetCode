class Solution {
public:
    
    
    bool isPossible(int mid, vector<int>v, int h){
        int cnt = 0;
        for(auto it : v){
            cnt += it/mid;
            it%mid!=0 ? cnt +=1 : cnt+=0;
        }
       return  cnt<=h ? true:  false;
    }
    int minEatingSpeed(vector<int>& v, int h) {
       int l = 1, r = 1000000000;
        while(l<r){
            int mid = (l+r)/2;
            if(isPossible(mid, v, h)==true){
                r = mid ;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
