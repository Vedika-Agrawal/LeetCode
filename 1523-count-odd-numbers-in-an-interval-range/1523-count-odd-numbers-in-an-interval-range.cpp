class Solution {
public:
    int countOdds(int low, int high) {
        // if(low==high)return low%2==0?0:1;
        if(low%2==0 && high%2==0)return (high-low)/2;
        // if(low%2!=0 && high%2!=0)return (high-low)/2+1;
        return (high-low)/2+1;
        
    }
};