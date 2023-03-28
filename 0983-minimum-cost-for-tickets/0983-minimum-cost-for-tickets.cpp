class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>&dp){
        if(i>=days.size())return 0;
        if(dp[i]!=0)return dp[i];
        
        int op1 = costs[0]+solve(days,costs,i+1,dp);
        int k = i;
        for(;k<days.size();k++){
            if(days[k]>=days[i]+7)break;
        }
        int op2 = costs[1] + solve(days,costs,k,dp);
        
         for(;k<days.size();k++){
            if(days[k]>=days[i]+30)break;
        }
        int op3 = costs[2] + solve(days,costs,k,dp);
        
        dp[i] = min(op1, min(op2,op3));
        return min(op1, min(op2,op3));
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),0);
        int ans = solve(days,costs,0,dp);
        return ans;
    }
    
};