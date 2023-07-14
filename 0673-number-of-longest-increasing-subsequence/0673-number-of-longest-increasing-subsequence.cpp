class Solution {
public:
    vector<int>inc,dp;
    int ans  = 0;
	int n;
    int mx = 0;
	
	void increasing(vector<int>&nums){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i]){
                    if(inc[j]+1>inc[i]){
                        inc[i]= inc[j]+1;
                        dp[i]=0;
                    }
                    if(inc[j]+1==inc[i]){
                        dp[i]+=dp[j];
                    }
                }
	        }
            mx = max(mx, dp[i]);
	    }
        
	    
	}
	
    int findNumberOfLIS(vector<int>& nums) {
        n= nums.size();
        inc.resize(n,1);
	    dp.resize(n,1);
	    increasing(nums);
        int mx  = *max_element(inc.begin(),inc.end());
        int res = 0;
        
        for(int i=0;i<n;i++){
            if(mx==inc[i]){
                res+=dp[i];
            }
        }
        return res;
        
    }
};