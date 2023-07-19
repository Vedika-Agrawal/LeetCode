class Solution {
public:
   static bool compare(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), compare);
        int cnt  = 0 ;
        int b  = INT_MIN;
        for(int i=0;i<arr.size();i++){
            int c  = arr[i][0];
            int d  = arr[i][1];
            if(b>c ){
                cnt++;
                b  = min(d,b);
            }
            else{
                b =  d;
            }
            
        }
        return cnt;
    }
    
};