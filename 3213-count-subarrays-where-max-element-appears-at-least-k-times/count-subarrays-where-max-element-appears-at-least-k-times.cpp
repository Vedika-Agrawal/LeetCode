#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll mx = *max_element(nums.begin(), nums.end());
        int i  = 0 , j = 0, n = nums.size();
        ll cnt  = 0;
        ll freq  = 0 ;
        ll atMost = k - 1;
        while(i<n){
           freq += nums[i]==mx ? 1 : 0;
           while(freq> atMost && j<= i){
             freq -= nums[j]==mx ? 1 : 0;
             j++;
           }
           cnt += (i - j +1);
           i++;
        }
        ll temp = ((ll)n * (n+1))/2;

         
        return temp - cnt;
    }
};