class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int n : nums) {
            if (n % 2 !=0)
                n*=2;
            
                s.insert(n);
        }
        int deviation = INT_MAX;
        while (true) {
            int max_val = *s.rbegin();
            deviation = min(deviation, max_val - *s.begin());
            if (max_val % 2 == 1)
                break;
            else {
                s.erase(max_val);
                s.insert(max_val / 2);
            }
        }
        return deviation;
    }
};

