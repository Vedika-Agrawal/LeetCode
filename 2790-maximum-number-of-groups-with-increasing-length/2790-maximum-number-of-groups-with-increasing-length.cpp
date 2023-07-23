class Solution {
public:
    int maxIncreasingGroups(vector<int>& v) {
        int ans = 0; long long sum = 0;
        sort(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            sum += v[i];
            if(sum >= (1ll*(ans+1)*(ans+2))/2) ans++;
        }
        return ans;
    }
};