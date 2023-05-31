class Solution {
public:
   
    
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
        
    for (int i=0; i<nums.size(); i++) {
        
        int l = i+1, r = nums.size()-1;
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                int tempIndex1 = l, tempIndex2 = r;
                while(l < r && nums[l] == nums[tempIndex1]) l++;
                while(l < r && nums[r] == nums[tempIndex2]) r--;
            }
        }
        while(i+1 < n && nums[i] == nums[i+1]) i++;

    }
    return res;
}
};