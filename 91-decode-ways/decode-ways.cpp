class Solution {
public:
    int len  ;

vector<int>dp;
 
 int solve(string s, int idx){
  if(idx==len)return 1;
  if(s[idx]=='0')return 0;
  if(idx==len-1 )return 1;
     if(dp[idx]!=-1)return dp[idx];
  int one = 0, two = 0;
  one = solve(s, idx+1);
  string str  = s.substr(idx,2);
  if(stoi(str)>=1 && stoi(str)<=26){
    two = solve(s, idx+2);
  }
  return dp[idx]=  one+two;
}


    int numDecodings(string s) {
        // n=s.size();
        len = s.size();
        dp.resize(len+1, -1);
        return solve(s,0);
    }
};