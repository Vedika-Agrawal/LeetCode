class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n+1))/2;
        int pivotIdx = -1;
        int currSum = 0;
        for(int i=1;i<=n;i++){
            currSum += i;
            int remSum = total - currSum + i;
            if(currSum == remSum)return i;
            
        }
        return -1;
    }
};