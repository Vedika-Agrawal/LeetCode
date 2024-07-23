class Solution {
public:
    bool static compare(pair<int,int>&p1, pair<int,int>&p2){
        if(p1.second<p2.second)return true;
        if(p1.second == p2.second && p1.first>p2.first)return true;
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums)mp[it]++;
        vector<pair<int,int>>v;
        for(auto it: mp){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), compare);
        vector<int> result;
        for (auto it : v) {
            for (int i = 0; i < it.second; ++i) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};