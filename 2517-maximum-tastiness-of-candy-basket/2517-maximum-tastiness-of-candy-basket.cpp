class Solution {
public:
    
     bool check(int mid, vector<int>& v, int k){
         int cnt = 1;
         int p = v[0];
         for(int i=1;i<v.size();i++){
             if((v[i]-p)>=mid)
             {
                 p = v[i];
                 cnt++;
             }
             
         }
         if(cnt>=k)return true;
         return false;
     }
    int maximumTastiness(vector<int>& v, int k) {
       sort(v.begin(),v.end());
        int l =  0 , r = 1e9;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid,v,k)){
                l = mid+1;
            }
            else r = mid-1;
        }
        return l-1;
    }
};