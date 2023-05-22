class Solution {
public:
    int mod = 1e9 +7;
    
    long long power(int a, int b){
        long long cal =1;
        while(b--){
            cal = (cal * a)%mod;
        }
        return cal;
    }
    
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long pre =0,  ans =0 ;
        
        for(auto it: nums){
            ans = (ans + power(it,3))%mod;
            ans = (ans + ((long long)power(it, 2) * pre) % mod) % mod;
            pre = (2*pre + it)%mod;
        }
        return ans;
    }
};