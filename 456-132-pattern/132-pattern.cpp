class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mn = 1e9;
        stack<pair<int,int>>st;
        for(auto it: nums){
            while(st.size() > 0 && st.top().first <= it) st.pop();
            if(!st.empty() && st.top().first > it && it >st.top().second ){
                return true;
            }
            st.push({it,mn});
            mn = min(mn, it);
        }
        return false;
    }
};