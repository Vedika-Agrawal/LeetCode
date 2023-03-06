class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        for(auto it : v){
            if(it<=k)k++;
        }
        return k;
    }
};