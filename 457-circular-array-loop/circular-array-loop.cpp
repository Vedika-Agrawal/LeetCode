#include <vector>
using namespace std;

class Solution {
public:
    vector<int> vis;
    int n;

    bool isCylclePresent(vector<int>& nums, int node, vector<int>& pathVisited, int dir) {
        if (pathVisited[node] == 1) return false;
        pathVisited[node] = 1;
        vis[node] = 1;

        int temp_idx = (nums[node] + node) % n;
        if (temp_idx < 0) temp_idx += n;

        if (dir == 1 && nums[node] < 0) return false;
        if (dir == 2 && nums[node] >= 0) return false;
        
        dir = (nums[node] >= 0) ? 1 : 2;

        if (node != temp_idx && pathVisited[temp_idx] == 1) return true;

        return isCylclePresent(nums, temp_idx, pathVisited, dir);
    }

    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        vis.resize(n, 0);

        for (int i = 0; i < n; i++) {
            vector<int> pathVisited(n, 0);
            if (vis[i] == 0) {
                int dir = 0; // (0 - > any, 1-> fowd , 2 -> back )
                if (isCylclePresent(nums, i, pathVisited, dir)) return true;
            }
        }

        return false;
    }
};
