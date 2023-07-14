class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    // int solve(vector<int>& prices,int idx,int c,int buy){
    //     if(c==2 || idx==n){
    //         return 0;
    //     }
    //     if(dp[idx][buy][c]!=-1){
    //         return dp[idx][buy][c];
    //     }
    //     int take=0,not_take=0;
    //     if(buy==0){
    //         take=-prices[idx]+solve(prices,idx+1,c,1);
    //         not_take=solve(prices,idx+1,c,buy);
    //     }
    //     else{
    //         take=prices[idx]+solve(prices,idx+1,c+1,0);
    //         not_take=solve(prices,idx+1,c,buy);
    //     }
    //     return dp[idx][buy][c]=max(take,not_take);
    // }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<vector<int>>(3,vector<int>(3,0)));
        int c=2;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int c=0;c<2;c++){
                    int take=0,not_take=0;
                    if(j==0){
                        take=-prices[i]+dp[i+1][1][c];
                    }
                    else{
                        take=prices[i]+dp[i+1][0][c+1];
                    }
                    not_take=dp[i+1][j][c];
                    dp[i][j][c]=max(take,not_take);
                }
            }
        }
        return dp[0][0][0];
    }
};