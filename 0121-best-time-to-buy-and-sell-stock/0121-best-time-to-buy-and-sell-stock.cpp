class Solution {
public:
    
    int maxProfit(vector<int>& v) {
        int mini = v[0];
        int ans =INT_MIN ;
        for(int i=0;i<v.size();i++){
        
            mini =min(mini, v[i]);
            ans = max(ans, v[i]-mini);
            
        }
        return ans;
    }
};