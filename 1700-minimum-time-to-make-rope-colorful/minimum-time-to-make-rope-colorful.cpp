class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int i=0;
        int n = col.size();
        int ans =0;
        while(i<n){
            int j= i+1;
            bool check= 0;
            int add  = time[i];
            int mx = time[i];
            while(j<n && col[j]==col[i]){
                add += time[j];
                mx = max(mx, time[j]);
                j++;
                check =1;
            }

            if(check==1){
                add-=mx;
                ans+=add;
            }
            i = j;
        }
        return ans;

    }
};