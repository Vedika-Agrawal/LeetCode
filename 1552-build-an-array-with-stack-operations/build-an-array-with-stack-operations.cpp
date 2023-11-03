class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i = 1;
        for(auto it: target){
            
            while(i<it){
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            
            } 
            ans.push_back("Push");
            i++;
            
        }
        return ans;
    }
};