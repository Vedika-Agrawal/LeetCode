class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(temp.size()==0 || temp[temp.size()-1]<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                auto idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
                continue;
            }
        }
        return temp.size();
    }
};