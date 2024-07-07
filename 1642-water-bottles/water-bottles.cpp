class Solution {
public:
    int numWaterBottles(int bottle, int ex) {
        int ans  =  bottle;
        while(bottle>=ex){
            int div  = bottle/ex;
            int rem = bottle%ex;
            ans+=div;
            bottle = div + rem;
        }
        return ans;

    }
};