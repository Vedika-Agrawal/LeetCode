class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int lo =0, hi =v.size()-1;
        while(lo<hi){
            int mid = (lo+hi)/2;
           if(mid%2==0 && v[mid]==v[mid+1] ){
               lo = mid+1;
           }
            else if(mid%2!=0 && v[mid]==v[mid-1]){
                lo = mid+1;
            }
            else 
                hi = mid;
        }
        return v[lo];
    }
};