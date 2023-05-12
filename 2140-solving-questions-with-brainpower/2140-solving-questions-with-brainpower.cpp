class Solution {
public:
    // long long ans = 0;
    int n;
    
    
    long long solve(vector<vector<int>>& ques , int idx, vector<long long>&dp ){
        
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int points  = ques[idx][0];
        int brain   = ques[idx][1];
        cout<<points<<" "<<brain<<endl;
        long long consider = points + solve(ques, idx+brain+1,dp);
        long long not_taken = solve(ques , idx+1,dp);
        
        return dp[idx] = max(consider, not_taken);
    }
    
    long long mostPoints(vector<vector<int>>& ques) {
        n= ques.size(); 
        vector<long long>dp(n,-1);
        return solve(ques,0,dp);
        
    }
};