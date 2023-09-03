class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long ans  = 0, total = 0 ;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            total  += nums[i] % m == k ? 1 : 0;
            if(total%m==k)ans++;
            int temp = total % m -k ;
            temp += temp<0 ? m : 0;
            ans+= mp[temp];
            mp[total%m]++;
        }
        return ans;
    }
};