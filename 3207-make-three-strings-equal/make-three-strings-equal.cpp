class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        int len = min({n, m, l});
        int ans = INT_MAX;
        for(int i = 0 ;i< len ; i++){
            if(s1.substr(0,i+1) == s2.substr(0,i+1) && s2.substr(0,i+1) == s3.substr(0,i+1)){
                int temp  = n-(i+1)+m-(i+1)+l-(i+1);
                ans=min(ans,temp);
            }
        }
        return (ans==INT_MAX ? -1:ans);
    }
};