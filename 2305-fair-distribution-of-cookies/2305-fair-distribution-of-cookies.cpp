class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>&cook, int k , int idx, vector<int>&temp){
        if(idx==cook.size()){
            int maxi = *max_element(temp.begin(), temp.end());
            ans = min(ans, maxi);
            return ;
        }
        for(int i=0;i<k;i++){
            temp[i]+=cook[idx];
            solve(cook, k,idx+1, temp);
            temp[i]-=cook[idx];
        }
        
        
    }
    int distributeCookies(vector<int>& cook, int k) {
        vector<int>temp(k,0);
        solve(cook, k, 0, temp);
        return ans;
    }
};