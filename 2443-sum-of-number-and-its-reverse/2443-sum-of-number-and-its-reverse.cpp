class Solution {
public:
      int reverseD(int num)
     {
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
 
    bool sumOfNumberAndReverse(int num) {
        int i=0;
        while(i<=num){
            if(i+reverseD(i)==num){
                return true;
            }
            i++;
        }
        return false;
        
    }
};