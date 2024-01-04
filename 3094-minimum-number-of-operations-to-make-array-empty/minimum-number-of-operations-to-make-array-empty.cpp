class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans = 0;
        for(auto it: mp){
            int n = it.second;
            if(n==1)return -1;
            ans += n/3;
            ans += (n%3==1 || n%3==2) ? 1 : 0;
        }
        return ans;

    }
};

