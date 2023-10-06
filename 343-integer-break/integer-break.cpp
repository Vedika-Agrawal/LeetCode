class Solution {
public:

    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int divi = n /3;
        int ans  =1;
        if(n%3==1){
            divi--;
            ans *= 2;
        }
         ans *= pow(3,divi);
         if(n%3)
        ans*=2;
        return ans;
    }
};