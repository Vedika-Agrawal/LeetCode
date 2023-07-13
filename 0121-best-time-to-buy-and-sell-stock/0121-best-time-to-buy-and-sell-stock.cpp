class Solution {
public:
    
    int n;
    int ans = INT_MIN;;
    int solve(vector<int>&v, int i, int mini){
       if(i==n)return ans;
        ans = max(ans, v[i]-mini);
        mini = min(mini,v[i]);
        return solve(v, i+1,mini);
    }
    
   int maxProfit(vector<int>& v) {
       n = v.size();
       int ans = solve(v, 1, v[0]);
       if(ans<0)return 0;
       return ans;
    }
};