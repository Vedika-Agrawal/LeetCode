class Solution {
public:
    vector<int>original;
    int n;
    Solution(vector<int>& nums) {
        n = nums.size();
        original = nums;
    }
    
    vector<int> reset() {
      return  original; 
    }
    
    vector<int> shuffle() {
        vector<int>shuffeld = original;
        
        int left = n;
        
        for(int i = n-1; i>+0;i--){
            int j = rand()% left;
            left--;
            swap(shuffeld[j],shuffeld[i]);
        }
        return shuffeld;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */