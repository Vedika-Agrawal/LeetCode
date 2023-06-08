class Solution {
public:
    int myAtoi(string s) {
        long long  ans =0;
        int n = s.size();
        int flag = 1;
        int check =0;
        for(int i=0;i<n;i++){
            while(i<n && s[i]==' ')i++;
            if(s[i]=='+' || s[i]=='-') { 
                flag = s[i]=='-' ? flag * -1 : flag;
                i++;
            }
            
            while(s[i]>='0' && s[i]<='9'){
                ans = ans * 10 + (s[i]-'0');
                if(ans*flag >=INT_MAX)return INT_MAX;
                if(ans*flag<=INT_MIN)return INT_MIN;
                i++;
                check=1;
            }
            
            return ans*flag;
        }
        return 0;
        
    }
};


