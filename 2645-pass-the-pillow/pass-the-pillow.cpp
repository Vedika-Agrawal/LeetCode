class Solution {
public:
    int passThePillow(int n, int time) {
       if(time<n){
           return time+1;
       }
        int rem = time%(n-1);
        int div = time/(n-1);
        if(div%2!=1)return rem+1;
        return n-rem;
    }
};