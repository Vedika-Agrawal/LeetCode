class Solution {
public:
    int digi_sum(long long n){
        int sum =0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum ;
    }
    long long makeIntegerBeautiful(long long n, int tar) {
         long long b = 1, or_no = n;
        while(digi_sum(n) > tar){
           n = n / 10 + 1;
            b *= 10;
        }
        return b*n-or_no;
    }
};