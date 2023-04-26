class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int sum  = 0 ;
            int ori =num;
            while(ori>0){
                sum+=ori%10;
                ori/=10;
            }
            num = sum;
        }
        return num;
    }
};