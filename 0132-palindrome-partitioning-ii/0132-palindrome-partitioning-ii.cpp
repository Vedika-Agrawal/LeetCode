class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // bool isPalindrome( string &s, int i, int j) {
    //     while (i < j) {
    //         if (s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    int solve(string &s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(s,i,j)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int a=1+solve(s,k+1,j);
                dp[i][j]=ans=min(ans,a);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        n=s.size();
        if(n==0){
            return 0;
        }
        if(isPalindrome(s,0,s.size()-1)){
            return 0;
        }
        dp.resize(n,vector<int>(n,-1));
        return solve(s,0,n-1);
    }
};