class Solution {
public:
    
   int maxProfit(vector<int>& v) {
        if(v.size()==1){
            return 0;
        }
        int mini = v[0];
        int ans = 0;
        for(int i=0;i<v.size();i++){
            ans = max(ans, v[i]-mini);
            mini =min(mini, v[i]);
        }
        return ans;
    }
};