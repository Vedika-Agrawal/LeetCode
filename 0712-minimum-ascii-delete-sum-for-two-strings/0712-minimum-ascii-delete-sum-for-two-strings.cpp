class Solution {
public:
    int ans = INT_MAX;
    vector<vector<int>>dp;
    int solve(string& s, string& t, int i, int j){
        if(i>=s.size() && j>=t.size())return 0;
        else if(i>=s.size()){
           return accumulate(t.begin()+j, t.end(), 0); 
            // int sum = 0;
            // while(j<t.size()){
            //     sum+= t[j];
            //     j++;
            // }
            // return sum;
        }
         else if(j>=t.size()){
             return accumulate(s.begin()+i, s.end(), 0); 
           // int sum = 0;
           //  while(i<s.size()){
           //      sum+= s[i];
           //      i++;
           //  }
           //  return sum;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int noMatch = INT_MAX;
        int match = INT_MAX;
        if(s[i]==t[j]){
            match = solve(s,t,i+1,j+1);
        }
        else{
            noMatch = min( s[i] + solve(s,t,i+1,j), t[j] + solve(s,t,i,j+1));
        }
        return dp[i][j] = min(match, noMatch);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        dp.resize(n+1, vector<int>(m+1,-1));
       return solve(s1,s2,0,0);
    }
};