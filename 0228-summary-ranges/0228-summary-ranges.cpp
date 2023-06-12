class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a =  nums[i];
            while(i< n-1 && nums[i]==nums[i+1]-1){
                i++;
            }
            cout<<a<<" "<<nums[i]<<endl;
            string s; 
            if(a!=nums[i])
             s = to_string(a) + "->" + to_string(nums[i]);
            else{
               s = to_string(a); 
            }
            // string s = "aa";
            ans.push_back(s);
        }
        return ans;
    }
};