class Solution {
public:
    // int findKthPositive(vector<int>& v, int k) {
    //     for(auto it : v){
    //         if(it<=k)k++;
    //     }
    //     return k;
    // }
    //  int findKthPositive(vector<int>& v, int k) {
    //      int l=0,h = v.size()-1;
    //      int mid;
    //      while(l<h){
    //          mid = (l+h)/2;
    //          if(v[mid]-1-mid<k)
    //              l = mid+1;
    //          else h = mid;
    //      }
    //      return l + k;
    // }
    
    int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};