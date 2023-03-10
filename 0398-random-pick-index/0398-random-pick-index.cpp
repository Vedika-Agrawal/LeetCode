class Solution {
public:
    vector<int>v;
    Solution(vector<int>& nums) {
        v  = nums;
        
    }
    
    int pick(int tar) {
        int n = 0, ans =-1;
        for(int i=0;i<v.size();i++){
            if(v[i]!=tar) continue;
            if(n==0){ ans =  i;n++ ;}
            else{
                n++;
                int j = rand()%n;
                if(j==0)ans =i;
                // if(rand()%n==0)ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */