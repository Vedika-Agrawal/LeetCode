
class Solution{
    public : 
     int longestConsecutive(vector<int>& nums){
         
        unordered_set<int> st({nums.begin(),nums.end()});
         int ans  = 0;
         for(auto it: nums){
             if(!st.count(it-1)){
                 int curr = it;
                 int temp = 1;
                 while(st.count(curr+1)){
                     curr++;
                     temp++;
                 }
                 ans = max(ans,temp);
                 
             }
         }
         return ans;
     }
};