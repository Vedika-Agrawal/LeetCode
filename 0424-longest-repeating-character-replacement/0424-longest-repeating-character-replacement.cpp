class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans = 0;
        int arr[26]= {};
        int cnt  = 0;
        for(;j<s.size();j++){
            arr[s[j]-'A']++;
            if(cnt<arr[s[j]-'A']){
                cnt = arr[s[j]-'A'];
                // cout<<cnt<<" "<<;
            }
            while(j-i+1 - cnt>k){
                arr[s[i]-'A']--;
                i++;

                for(int m =0;m<26;m++) cnt = max(cnt, arr[m]);
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};