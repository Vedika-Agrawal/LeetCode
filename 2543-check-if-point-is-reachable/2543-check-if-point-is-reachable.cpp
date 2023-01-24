class Solution {
public:
    bool isReachable(int x, int y) {
      int k = gcd(x,y);
      while(k%2==0){
          k/=2;
      }
      return k==1;  
    }
};