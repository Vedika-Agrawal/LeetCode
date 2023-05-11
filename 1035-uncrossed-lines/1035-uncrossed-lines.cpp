class Solution {
public:
    int n, m;
    int dp[501][501];
    
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        
        if(i >= m || j >= n) {
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(nums1[i]==nums2[j]){
            return dp[i][j] =  1+ solve(i+1, j+1, nums1, nums2);
        }
        else{
            int a =  solve(i, j+1, nums1, nums2);
            int b =  solve(i+1, j, nums1, nums2) ;
            
            return dp[i][j] =  max( a, b);
        }
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       m = nums1.size(), n = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,0,nums1,nums2);
        
//            m = nums1.size();
//         n = nums2.size();
        
//         memset(t, -1, sizeof(t));
        
//         return solve(0, 0, nums1, nums2);
    }
    
};