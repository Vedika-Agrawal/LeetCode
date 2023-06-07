class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            if(dq.size() && dq.front()==i-k)dq.pop_front();
            int curr = nums[i];
            while(dq.size() && nums[dq.back()]< curr)dq.pop_back();
            dq.push_back(i);
            // ans.push_back(nums[dq.front()]);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};