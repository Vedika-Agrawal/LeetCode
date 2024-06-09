class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int ans  = 0,sum= 0 ;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<v.size(); i++){
            sum+=v[i];
            int rem = sum%k;
            if(rem<0)rem+=k;
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
        
        
    }
};