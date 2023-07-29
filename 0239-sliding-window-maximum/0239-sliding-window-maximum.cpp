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

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& v, int k) {
//         vector<int>ans;
//         priority_queue<pair<int,int>>q;
//         for(int i=0;i<k;i++)q.push({v[i], i});
//         ans.push_back(q.top().first); // 3 3 
        
//         for(int i=k;i<v.size();i++){
//             q.push({v[i], i}); // add curr ele to the q; // -1=0 3=1 -1=2 -3=3 5=4
            
//             while(q.top().second<=i-k) q.pop();
               
//             ans.push_back(q.top().first);
            
            
            
//         }
//         return ans;
//     }
// };