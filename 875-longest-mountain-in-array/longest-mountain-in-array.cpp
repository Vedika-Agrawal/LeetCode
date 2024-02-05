class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans =0, cnt =  1; bool flag = 0;
        for(int i=1;i<arr.size();i++){
            // increasing ============
            if(arr[i]>arr[i-1]){
                if(flag==1) flag= 0, cnt =1;
                cnt++;
            }
            //decreasing ===================
            else if(cnt>=2 && arr[i]<arr[i-1]){
                flag= 1; cnt++;
                ans = max(ans, cnt);
            }
            else cnt=1;

        }
        return ans;
    }
};