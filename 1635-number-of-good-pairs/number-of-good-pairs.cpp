class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>v(101,0);
        int ans  =0 ;
        for(auto it: nums){
            ans  += v[it];
            v[it]++;
        }
        return ans;
    }
};