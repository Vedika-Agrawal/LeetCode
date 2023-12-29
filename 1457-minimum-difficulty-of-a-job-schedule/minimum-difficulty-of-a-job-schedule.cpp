#define ll long long
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    ll solve(vector<int>&job, int idx,int grp_left){
        if(grp_left<0 || idx>n )return INT_MAX;
        if(grp_left==0 && idx==n)return 0;
        if(dp[idx][grp_left]!=-1)return dp[idx][grp_left];
        ll mx = INT_MIN, ans = INT_MAX;    
        for(int i= idx;i<n;i++){
           mx = max(mx, 1ll * job[i]);
        // mx = job[i];
           ans = min(ans, mx + solve(job, i+1, grp_left-1));
        }
        return dp[idx][grp_left] =ans;

    }
    int minDifficulty(vector<int>& job, int d) {
        n=job.size();
        if(d>n){
            return -1;
        }
        dp.resize(n+1, vector<int>(d+1, -1));
        int x=solve(job,0,d);
        return x;
    }
};

