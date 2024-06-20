#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& pos, int m, int minForce) {
        int cnt = 1;
        int lastPlaced = pos[0];
        for(int i = 1; i < pos.size(); i++) {
            if(pos[i] - lastPlaced >= minForce) {
                cnt++;
                lastPlaced = pos[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int l = 1, h = pos.back() - pos[0];
        int ans = 0;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(isPossible(pos, m, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
