class Solution {
public:
    int dominantIndex(vector<int>& v) {
        int maxi = *max_element(v.begin(),v.end());
        // cout<<maxi<<endl;
        // int pos = find(v.begin(),v.end(),maxi);
        int idx;
        for(int i=0;i<v.size();i++){
            if(maxi==v[i]){
                idx = i;
                break;
            }
        }
        sort(v.begin(),v.end());
        int n = v.size();        
        if(v[n-2]*2 > v[n-1])return -1;
        else 
            return idx;
    }
};