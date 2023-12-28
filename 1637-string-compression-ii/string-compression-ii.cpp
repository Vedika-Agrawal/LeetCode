int t[101][27][101][101];
class Solution {
public:
// int t[101][27][101][101];
    int solve(string &s, int i, int prev, int freq, int k){
        if(k < 0) return INT_MAX;
        if(i >= s.length()) return 0;
        if(t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }
        int notTake = solve(s, i+1, prev, freq, k-1);
        int take = 0;
        if(prev == s[i]-'a'){
            int temp = 0;
            if(freq==1 || freq == 9 || freq == 99){
                temp ++;
            }
            take =temp +  solve(s,i+1,prev,freq+1,k);
        }
        else{
            take = 1 + solve(s, i+1, s[i]-'a',1,k);
        }
        return t[i][prev][freq][k] =min(take, notTake);
    }
    int getLengthOfOptimalCompression(string s, int k) {
         memset(t, -1, sizeof(t));
        return solve(s,0,26,0,k);
    }
};