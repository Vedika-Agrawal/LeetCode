class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0 , j = a.size()-1;
        int ans  =0  ;
        while(i<j){
            int area  = min(a[i],a[j]) * (j-i);
            if(area>ans){
                ans = area;
            }
            if(a[i]<=a[j]){
                i++;
            }
            else{
                j--;
            }
            
        }
        return ans;
    }
};