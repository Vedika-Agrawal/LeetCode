class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
       priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(!pq.empty() && k--){
            
            pq.pop();
        }
        return pq.top();
        // return 0;
        
    }
};