class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int i = n-1,j=n-1;
        int a =0, b=0,c =0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            if(s[i]=='b')b++;
            if(s[i]=='c')c++;
            
        }
        int ans = INT_MAX;
        if(a<k || b<k || c<k)return -1;
        while(i>=0){
            if(s[i]=='a')a--;
            if(s[i]=='b')b--;
            if(s[i]=='c')c--;
            while(a<k || b<k || c<k){
                if(s[j]=='a')a++;
                if(s[j]=='b')b++;
                if(s[j]=='c')c++; 
                j--;
            }
            i--;
            ans = min(ans, n -j +  i );
        }
        return ans;
    }
};