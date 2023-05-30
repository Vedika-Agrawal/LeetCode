class Solution {
public:
   double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(x==1){
            return x;
        }
        long long nn=n;
        if(n<0){
            nn=-1*nn;
        }
        double ans=1;
        while(nn>0){
            if(nn%2==0){
                x=x*x;
                nn/=2;
            }
            else{
                ans=ans*x;
                nn--;
            }
        }
        if(n<0){
            ans=(double)1/(double)ans;
        }
        return ans;
    }
};