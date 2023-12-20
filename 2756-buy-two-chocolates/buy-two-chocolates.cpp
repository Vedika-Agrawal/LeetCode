class Solution {
public:
    int buyChoco(vector<int>& p, int money) {
        sort(p.begin(),p.end());
        int sum = p[0] + p[1];
        int ans = money-sum;
        if(ans>=0)return ans;
        return money;
    }
};
