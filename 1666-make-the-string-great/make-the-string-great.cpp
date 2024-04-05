class Solution {
public:
    string makeGood(string& s) {
        int n=s.size();
        string ans=string(1, s[0]);
        for(int i=1; i<n; i++){
            if (!ans.empty() && s[i]!=ans.back() 
            && (s[i]&31)==(ans.back()&31))//Note 'a'='A'+32 1-bit different
                ans.pop_back();
            else 
                ans.push_back(s[i]);
        }
        return ans;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();