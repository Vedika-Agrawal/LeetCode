class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i= 0, j= 0;
        while(i<n){
            int cnt  = 1;
            while(i+1<n && nums[i]==nums[i+1]){
                cnt++;
                i++;
            }
            nums[j++] = nums[i];
            if(cnt>=2){
                nums[j++] = nums[i];
            }
            i++;
        }
        return j;
    }
};