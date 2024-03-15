class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix =1, suff = 1;
        int cnt =  0;

        for(auto it: nums) {
            if(cnt == 0 && it==0){
                cnt++;
                continue;
            }
            if(cnt==0){
                prefix*=it;
            }
            if(cnt==1){
                suff *=it;
            }
        }
        if(cnt>1){
            vector<int>ans(nums.size(), 0);
            return ans;
        }
        if(cnt==0){
            vector<int>ans;
            for(auto it: nums){
                ans.push_back(prefix/it);
            }
            return ans;

        }
        else{
            vector<int>ans;
            bool f = false;
            for(auto it: nums){
                if(it==0){
                    f = true;
                    ans.push_back(prefix*suff);
                }
                else{
                    ans.push_back(0);
                }
            }
            return ans;
        }
    }
};