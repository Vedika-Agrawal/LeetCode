class Solution {
public:
    int maxProfit(vector<int>& p) {
        int prf =0 ;
        int mini = INT_MAX;
        for(int i=0;i<p.size();i++){
            if(mini>p[i]){
                mini = p[i];
            }
            if(prf< p[i]-mini){
                prf = p[i]-mini;
            }
        }
        return prf;
    }
};