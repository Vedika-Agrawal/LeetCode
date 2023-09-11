class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        vector<vector<int>>ans;
        map<int, vector<int>>mp;
        for(int i=0;i<gp.size();i++){
          mp[gp[i]].push_back(i);
        }
        for(auto it: mp){
            vector<int>temp;
            int a = it.first;
            auto b = it.second;
            // cout<<a<<" "<<b.size()<< endl;
            int i=0;
            while(i<b.size()){
                temp.push_back(b[i++]);
                if(temp.size()==a){
                    ans.push_back(temp);
                    temp.clear();
                }
                

            }
        }

        return ans;
    }
};