class Solution {
public:
    int closetTarget(vector<string>& wd, string tar, int st) {
        int ans  = INT_MAX;
        int n = wd.size();
        for(int i=0;i<wd.size();i++){
            string str = wd[i];
            if(str==tar){
               ans = min(ans,abs(i-st));
                ans = min(ans,n-abs(i-st));
            }
        }
        // (ans!=INT_MAX) ? return ans : return -1;
        if(ans!=INT_MAX)
        return ans;
        return -1;
        
      // int x =  (ans==INT_MAX)? return -1 : return ans;
    }
};