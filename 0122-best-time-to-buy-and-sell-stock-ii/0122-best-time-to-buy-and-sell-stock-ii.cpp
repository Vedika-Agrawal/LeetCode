class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans  = 0;
        int curr  = v[0];
        for(int i=1;i<v.size(); i++){
            if(v[i]-curr>0){
                ans += v[i]-curr;
              
            }
              curr = v[i];
        }
        return ans;
    }
};