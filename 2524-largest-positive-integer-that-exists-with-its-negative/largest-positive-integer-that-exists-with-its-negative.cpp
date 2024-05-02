class Solution {
public:
    int findMaxK(vector<int>& v) {
        vector<int>ans;
        int res =-1;
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                mp[v[i]]++;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]<0){
                if(mp.find(v[i]*-1)!=mp.end()){
                    ans.push_back(v[i]*-1);
                }
            }
        }  
        
        sort(ans.rbegin(),ans.rend());
        if(ans.size()>0)return ans[0];
        return res;
    }
};