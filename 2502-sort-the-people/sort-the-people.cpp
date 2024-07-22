class Solution {
public:
    vector<string> sortPeople(vector<string>& name, vector<int>& ht) {
        vector<pair<int,string>>v;
        for(int i=0;i<ht.size();i++){
            int h = ht[i];
            string temp = name[i];
            v.push_back({h,temp});
        }
        sort(v.begin(),v.end());
        int i=0;
        for(auto &it: v){
            name[i] = it.second;
            i++;
        }
        reverse(name.begin(),name.end());
        
        return name;
    }
};