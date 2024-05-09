class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        sort(v.rbegin(),v.rend());
        long long ans  = 0;
        int sub = 0 ;
        for(int i=0; i<k ; i++){
            int temp = v[i]-sub;
            if(temp<=0)break;
            ans += temp;
            sub++;
            
        }
        return ans;
    }
};