class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = nums1.size()-1;
        while(i>=0 && j>=0){
            if(nums2[j]>=nums1[i]){
                nums1[k] = nums2[j];
                j--;
            }
            else{
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }
        if(i<0){
            while(j>=0){
                nums1[k--] = nums2[j--];
                
            }
        }
        if(j<0){
            while(i>=0){
                nums1[k--] = nums1[i--];
                
            }
        }
    }
};