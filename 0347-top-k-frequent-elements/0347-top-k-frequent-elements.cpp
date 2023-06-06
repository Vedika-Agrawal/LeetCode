class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it :  nums){
            mp[it]++;
        }
        vector<int>ans;
        
         priority_queue<pair<int,int>>pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        
        while(k--){
            int a = pq.top().second;
            pq.pop();
            ans.push_back(a);
        }
        return ans;
    }
};