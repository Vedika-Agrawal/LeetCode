class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int cnt  = 0;
        for(auto it : s){
            if(mp.find(it)!=mp.end()){
                cnt++;
                mp.clear();
                mp[it]++;
            }
            else{
                mp[it]++;
            }
        }
        return cnt+1;
    }
};