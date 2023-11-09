class Solution {
public:
    int countHomogenous(string s) {
        long cnt = 0;
        int n = s.size();
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            int j = i;
            while(j+1<n && s[j+1]==s[i])j++;

            long k = j-i+1;
            cnt = cnt + ((k)*(k+1))/2%mod;
            i= j;
        }
        return cnt%mod;
    }
};