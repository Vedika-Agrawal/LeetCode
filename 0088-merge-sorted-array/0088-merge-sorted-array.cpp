class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int idx = n+m-1;
        while( i>=0 && j>=0 ){
            if(nums2[j] >= nums1[i]){
                nums1[idx] = nums2[j];
                j--;
            
                
            }
            else{
                 nums1[idx] = nums1[i];
                i--;
               
            }
             idx--;
        }
        
         while(i>=0){
            nums1[idx]=nums1[i];
            i--;
            idx--;
        }
         while(j>=0){
            nums1[idx]=nums2[j];
            j--;
            idx--;
        }
    }
};


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                swap(nums1[i],nums2[j]);
                i++;
            }
        }
        while(i<(m+n) && j<n){
            nums1[i++]=nums2[j++];
        }
}