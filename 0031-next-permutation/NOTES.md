1.Easily solved using STL :
next_permutation(nums.begin(), nums.end());
2. fing all permutation
3.   step 1: find(arr[i]<arr[i+1]) = idx 1;
step 2: traverse from lst. And find the idx such that arr[j]>arr[i] = idx 2
step 3: swap (arr[i],arr[j);
step 4: reverse(arr(i+1) sa.
class Solution {
public:
void nextPermutation(vector<int>& nums) {
int n = nums.size(), k, l;
for (k = n - 2; k >= 0; k--) {
if (nums[k] < nums[k + 1]) {
break;
}
}
if (k < 0) {
reverse(nums.begin(), nums.end());
} else {
for (l = n - 1; l > k; l--) {
if (nums[l] > nums[k]) {
break;
}
}