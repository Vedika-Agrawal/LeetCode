class Solution {
public:
    double solve(double x, long n){
        if(n==0)return 1;
        if(n<0){
            return solve(1/x, -1*n);
        }
        if(n%2==0){
            return solve(x*x, n/2);
        }
        else{
            return solve(x*x,n/2)*x;
        }
    }
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};