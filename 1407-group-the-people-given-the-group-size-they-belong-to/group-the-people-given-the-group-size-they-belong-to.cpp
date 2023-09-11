class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        
        for (int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        
        for (auto it : mp) {
            vector<int> temp;
            int groupSize = it.first;
            auto people = it.second;
            
            for (int i = 0; i < people.size(); i++) {
                temp.push_back(people[i]);
                
                if (temp.size() == groupSize) {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return ans;
    }
};
