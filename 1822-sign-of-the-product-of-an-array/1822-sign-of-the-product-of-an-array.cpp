class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        
        for(auto it : nums){
            if(it<0)cnt++;
            if(it==0){
                return 0;
            }
        }
        return cnt%2==0 ?1 : -1;
    }
};