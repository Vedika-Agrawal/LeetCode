class Solution {
public:
    int totalFruit(vector<int>& v) {
        unordered_map<int,int>mp;
        int j=0, i=0;
        int ans =0 ;
        // set<int>st;
        
        while(j!=v.size()){
            mp[v[j]]++;
            if(mp.size()>2){
                mp[v[i]]--;
                if(mp[v[i]]==0)mp.erase(v[i]);
                i++;
            }
            j++;
            ans= max(ans, j-i);
        }
        return ans;
    }
};