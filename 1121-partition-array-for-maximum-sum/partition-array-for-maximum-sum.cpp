class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&arr, int k, int stIdx){
        if(stIdx>=arr.size())return 0;
        if(dp[stIdx]!=-1)return dp[stIdx];
        int mx = arr[stIdx]; 
        int ans = arr[stIdx]; 

        for(int currIdx = stIdx ; currIdx<arr.size() && currIdx<stIdx+k; currIdx++){
            mx = max(mx, arr[currIdx]);
            int temp = mx * (currIdx - stIdx +1) + solve(arr, k, currIdx+1);
            ans = max(ans, temp);
        }
        return dp[stIdx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return solve(arr, k, 0);
    }
};