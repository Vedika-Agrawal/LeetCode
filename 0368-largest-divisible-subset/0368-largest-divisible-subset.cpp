class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> dp(n,1),hash(n,0);
        int mx = 0, idx ;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]% arr[j]==0 && dp[j]+1> dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>mx){
                mx= dp[i];
                idx= i;
            }
        }
          vector<int>ans(mx);
            while(idx!= hash[idx]){
                int val = arr[idx];
                ans[mx-1] = val;
                mx--;
                idx = hash[idx];
            }
            ans[0] = arr[idx];

        return ans;
        
        
    }
};