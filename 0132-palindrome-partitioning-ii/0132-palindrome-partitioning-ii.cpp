class Solution {
public:
    int n ;
    
//     bool isPalindrome(string S){
//         int i=0;
//         int j=S.length()-1;
        
//         while(j>i){
//             if(S[i]==S[j]){
//                 i++;
//                 j--;
//             }
//             else{
//                 return false;
//             }
//         }
        
//         return true;
//     }
    vector<vector<int>>dp;
    
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int st, int end){
        if (st >=end ) return 0;
        if(dp[st][end]!=-1)return dp[st][end];
        int ans = INT_MAX;
        for(int k = st; k<end; k++){
            // string temp = s.substr(st,k);
            if(isPalindrome(st,k,s)){
                int cnt = 1 + solve(s, k+1, end);
                ans = min(ans, cnt);
            }
        }
        return dp[st][end] = ans;
    }
   
    
    int minCut(string s) {
        n= s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n) -1  ;
    }
};