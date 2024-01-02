class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            bool check = 0;
            for(auto &it: ans){
                int sz = it.size();
                cout<<nums[i]<<" "<<it[sz-1]<<" "<<i<<endl;
                if(it[sz-1]!=nums[i]){
                    it.push_back(nums[i]);
                    check = 1;
                    break;
                }
            }
            if(check==0){
                vector<int>v = {nums[i]};
                ans.push_back(v);
            }

        }
        return ans;
    }
};