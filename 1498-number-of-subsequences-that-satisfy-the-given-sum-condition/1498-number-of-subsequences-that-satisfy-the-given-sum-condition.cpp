class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int l =0, h=  nums.size()-1;
        int ans = 0;
        int MOD = 1e9+7;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>pow(n,1);
        for(int i=1;i<n;i++){
            pow[i] = pow[i-1]*2 %MOD;
        }
        while(l<=h){
            if(nums[h]+nums[l]>target){
                h--;
            }
            else{
                int temp = pow[h-l]%MOD;
                ans = (ans + temp)%MOD;
                l++;
            }
        }
        return ans;
        
    }
};