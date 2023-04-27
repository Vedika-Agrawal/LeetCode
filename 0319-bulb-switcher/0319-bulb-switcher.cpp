class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            long long sr = sqrt(i);
            if(sr * sr == i)ans++;
        }
        return ans;
    }
};