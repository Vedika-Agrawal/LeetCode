class Solution {
public:
    vector<int> mergerTwoSortedArray(vector<int>&left, vector<int>&right){
        int i =0, j=0;
        int n = left.size();
        int m = right.size();
        vector<int>ans(n+m);
        int k = 0;
        while(i<n && j<m){
            if(left[i]<=right[j]){
                ans[k]=left[i];
                i++;
                k++;
            }
            else{
                ans[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<n){
            ans[k++]=left[i++];
        }
        while(j<m){
            ans[k++]=right[j++];
        }
        return ans;
    }
    vector<int> mergeSort(vector<int>&v, int st, int end){
        if (st == end) {
            return {v[st]};
        }
        
        int mid = st + (end - st) / 2;
        auto left  = mergeSort(v, st, mid);
        auto right  = mergeSort(v, mid+1, end);
        return mergerTwoSortedArray(left, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};