class Solution {
public:
    #define ll long long
  ll check(vector<int> &counts, int g1, int g) {
    ll groups = 0;
    for (int &cnt : counts) {
        bool found = false;
        for (int p = cnt / g1; p >= 0 && !found; --p)
            if ((cnt - p * g1) % g == 0) {
                groups += p + (cnt - p * g1) / g;
                found = true;
            }
        if (!found)
            return INT_MAX;
    }
    return groups;
}
    
    int minGroupsForValidAssignment(vector<int>& nums) {
        ll n=nums.size();
        unordered_map<int,int> mp;
        for(auto &c:nums)
            mp[c]++;
        
        vector<int> freq;
        for(auto &it:mp){
            freq.push_back(it.second);
        }
     
        sort(freq.begin(),freq.end());
        
        ll ans = INT_MAX;
        
        for(int i=freq[0];i>=1;i--){
            ans = check(freq,i+1,i) ;
            if(ans<INT_MAX) return ans;
        }
        if(ans>=INT_MAX)
            ans=-1;
        
        return ans;
        
        
    }
};