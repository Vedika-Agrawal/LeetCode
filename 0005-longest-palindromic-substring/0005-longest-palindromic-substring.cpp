class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int mx=1;
        int st=0,en=0;
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap+i;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    if(s[i]==s[j] && s[j-1]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]==1 && mx<gap+1){
                    mx=gap+1;
                    cout<<mx<<endl;
                    st=i;
                    en=j;
                }
            }
        }
        return s.substr(0+st,mx);
    }
};