class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int>count(32, 0);
        for(auto it  : nums){
            for(int i =0 ; i< 31; i++){
                int currMask = pow(2, i);
                int temp = currMask & it;
                if(temp!=0){
                    count[i]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0 ;i<32; i++){
            if(count[i]>=k){
                ans += pow(2, i);
            }
        }
        return ans;
    }
};