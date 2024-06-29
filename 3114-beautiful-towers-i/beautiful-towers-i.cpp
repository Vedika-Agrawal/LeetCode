class Solution {
public:
    
    long long maximumSumOfHeights(vector<int>& h) {
        long long sum = 0;
        int sz = h.size();
        for(int indx = 0; indx < sz; indx++){
            sum = max(findSum(h, indx), sum);
        }
        return sum;
    }
private:
    long long findSum(vector<int> h, int maxIndx){
        long long sum = 0;
        int sz = h.size();
        for(int indx = maxIndx - 1; indx > -1; indx--){
            if(h[indx] > h[indx+1])h[indx] = h[indx+1];
        }
        for(int indx = maxIndx + 1; indx < sz; indx++){
            if(h[indx] > h[indx-1])h[indx] = h[indx-1];
        }
        for(int indx = 0; indx < sz; indx++){
            sum += h[indx] * 1ll;
        }
        return sum;
    }
};