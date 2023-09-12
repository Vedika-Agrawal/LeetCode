class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto it : s) mp[it]++;
        vector<int>v;
        set<int>st;
        for(auto it:mp)v.push_back(it.second);
        sort(v.begin(),v.end());
        int ans  = 0;
        for(auto it: v){
            int temp = it;
            while(st.count(temp)!=0 && temp>0){
                temp --;
                ans++;
            }
           if(temp==0)continue;
           st.insert(temp);
        }
        return ans;
    }
};