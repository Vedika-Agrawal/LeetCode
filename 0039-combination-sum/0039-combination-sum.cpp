class Solution {
public:
   vector<vector<int>> res;
    void solve(vector<int>& candidates,int i,vector<int> temp,int target){
        if(i==candidates.size()){
            return;
        }
         if(target==0){
            res.push_back(temp);
             return;
        }
        
        solve(candidates,i+1,temp,target);
        if(target-candidates[i]>=0){
            temp.push_back(candidates[i]);
            target-=candidates[i];
            solve(candidates,i,temp,target);
        }
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> temp;
        solve(candidates,0,temp,target);
        return res;
    }
};