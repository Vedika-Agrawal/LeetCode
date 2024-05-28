class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0,ans=0,sum =0;
        for(int j =0;j<s.size();j++){
            if(s[j]!=t[j]){
                sum+= abs(s[j]-t[j]);
            }
            while(sum>maxCost){
                int temp = abs(s[i]-t[i]);
                sum-=temp;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};