class Solution {
public:
    
    typedef long long ll;
    
    bool isValid(vector<int>v, int mid){
        if(v[0]>mid)return false;
        ll prev  = v[0];
        for(int i=1;i<v.size();i++){
            ll diff  = mid- prev;
            prev = v[i] - diff;
            if(prev > mid)return false;
            
        }
        return true;
    }
    
    
    int minimizeArrayValue(vector<int>& v) {
        int ans;
        int l =0 , h = *max_element(v.begin(), v.end());
        while(l<=h){
            int mid = (l+h)/2;
            if(isValid(v,mid)){
                ans = mid ; 
                h = mid -1;
            }
            else{
                l = mid +1 ;
            }
        }
        return ans;
    }
};