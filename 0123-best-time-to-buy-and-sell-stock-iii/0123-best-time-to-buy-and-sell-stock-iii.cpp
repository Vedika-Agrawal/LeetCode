typedef  vector<int> p;
class Solution {
public:
    int n;
    int maxProfit(vector<int>& v) {
        n = v.size();
        vector< vector<p>>dp(n+1, vector<p>(3, p(3,0)));
        
        for(int idx= n-1; idx>=0;idx--){
            for(int buy = 0; buy<2;buy++){
                for(int cnt =0; cnt<2;cnt++){
                    int profit = 0;
                    if(buy==0) profit  = max( -v[idx] + dp[idx+1][1][cnt], dp[idx+1][0][cnt]);
                    else profit  = max( v[idx] + dp[idx+1][0][cnt+1], dp[idx+1][1][cnt]);
                     
                    
                    dp[idx][buy][cnt] = profit;   
                    
                }
            }
        }
        return dp[0][0][0];
    }
    
};