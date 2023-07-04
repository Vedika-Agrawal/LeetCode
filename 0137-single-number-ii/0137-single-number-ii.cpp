class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0 ;
        for(int k=0;k<32;k++){
            
            int temp = (1<<k);
            int zero=0, one= 0;
            for(auto it: nums){
                if((it & temp)==0)zero++;
                else one++;
            }
            if(zero%3==0){
                res = (res | temp);
            }
        }
        return res;
    }
};