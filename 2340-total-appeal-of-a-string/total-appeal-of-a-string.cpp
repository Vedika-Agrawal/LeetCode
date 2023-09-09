class Solution {
public:

    long long appealSum(string s) {
        long long ans  = 0;
        vector<int>v(26, 0);
        for(int i=0;i<s.size();i++){
            v[ s[i]-'a'] = i+1;
            int sum = accumulate(v.begin(),v.end(),0);
            ans += sum;
        }
        return ans;
    }
};
