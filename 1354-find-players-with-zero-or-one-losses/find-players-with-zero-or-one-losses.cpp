class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>>ans;
        unordered_map<int,int> win ,loose;
        for(auto it: m){
            int w = it[0]; 
            int l =it[1];
            
            // win me tabhi dalo jab loose me useke count 0 ho.
            if(loose.find(w)==loose.end())
                win[w]++;
            
            // loose me ayi ha na tho use win se remove kr do. or few inc    kr do in loose vecteo
            win.erase(l);
            loose[l]++;
            
        }
        vector<int>v,k;
        for(auto it: win){
            v.push_back(it.first);
        }
        for(auto it: loose){
            if(it.second == 1)k.push_back(it.first);
        }
        sort(v.begin(),v.end());
        sort(k.begin(),k.end());

        ans.push_back(v);
        ans.push_back(k);
        return ans;
    }
};