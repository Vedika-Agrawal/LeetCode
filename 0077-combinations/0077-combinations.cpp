class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(int end, int k, vector<int>&temp,int st){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for(int t = st; t<=end;t++){
            temp.push_back(t);
            solve(end, k, temp, t+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n,k,temp,1);
        return ans;
    }
};