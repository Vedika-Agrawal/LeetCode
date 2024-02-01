class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i; 
            vector<int>temp;
            while(j<n && j<i+3 && nums[j]-nums[i]<=k){
                temp.push_back(nums[j]);
                j++;
            }
            if(temp.size()!=3 || temp[2]-temp[0]>k)return {};
            ans.push_back(temp);
            i = j-1;
        }
        return ans;
    }
};