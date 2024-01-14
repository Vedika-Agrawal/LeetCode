class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!= w2.size())return false;
        unordered_map<char,int>v1,v2;
        for(auto it: w1){
            v1[it]++;
        }
        for(auto it: w2){
            if(v1[it]==0)return false;
            v2[it]++;
        }
        for(auto it: w1){
            if(v2[it]==0)return false;
        }
        vector<int>k,t;
        for(auto it: v1){
            k.push_back(it.second);
        }
        for(auto it: v2){
            t.push_back(it.second);
        }
        sort(k.begin(),k.end());
        sort(t.begin(),t.end());
        return k==t;
        return 0;
    }
};