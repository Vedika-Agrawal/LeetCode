class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        
        int n = nums.size(); 
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
           for (int j = i + 1; j < n; j++) {
                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;
              
                
               int l = j + 1;
               int r = n - 1;
                
                while(l<r){
                    
                    long long sum = nums[i];
                sum += nums[j];
                sum += nums[r];
                sum += nums[l];
                    
                    if(sum==tar){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++,r--;
                       
                        while(l<r && nums[l]==nums[l-1])l++;
                        while(l<r && nums[r]==nums[r+1])r--;
                        
                    }
                    else if(sum<tar){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
            }
           
        }
        return ans;
    }
};