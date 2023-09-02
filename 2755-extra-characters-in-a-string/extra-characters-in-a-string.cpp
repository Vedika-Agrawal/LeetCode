class Solution {
public:
    set<string>st;
    vector<int> dp;
    int solve(string s, int idx){
        if(idx>=s.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        string curr = "";
        int mini = s.size();
        for(int i=idx;i<s.size();i++){
            curr.push_back(s[i]);
            int curr_len = (st.count(curr)!=0) ? 0 : curr.size();
            int next_len = solve(s, i+1);
            mini = min(mini, curr_len + next_len);
        }
        return dp[idx] = mini;
    }
    int minExtraChar(string s, vector<string>& dic) {
        for(auto it :dic)st.insert(it);
        dp.resize(51,-1);
        return solve(s,0);
    }
};