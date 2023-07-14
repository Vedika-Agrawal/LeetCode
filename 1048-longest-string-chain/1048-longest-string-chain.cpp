class Solution {
public:
    static bool compare (string s1, string s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(),arr.end(), compare);
        int n = arr.size();
        vector<int>dp(n,1);
        int ans  =0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string s = arr[i], t = arr[j];
                if(s.size()-1 ==t.size()){
                    int k=0,l=0;
                    while(k<s.size()){
                        if(s[k]==t[l]){
                              k++;l++;
                        }
                        else{
                            k++;
                        }
                      
                    }
                    if(l==t.size()){
                        dp[i]= max(dp[i], dp[j]+1);
                
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};