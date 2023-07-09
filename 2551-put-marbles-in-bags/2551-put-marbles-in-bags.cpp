#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n = v.size();
        if(k==1 || n==k)return 0;
        
        vector<ll>temp;
        for(int i=1;i<n;i++){
            temp.push_back(v[i]+v[i-1]);
        }
        
        
        sort(temp.begin(),temp.end());
        ll mini =0 , maxi=0 ;
       
        
        for(int i=0;i<k-1;i++){
            mini += temp[i];
            maxi += temp[n-i-2];
        }
       
        return maxi - mini;
        
        
        
        
        
    }
};