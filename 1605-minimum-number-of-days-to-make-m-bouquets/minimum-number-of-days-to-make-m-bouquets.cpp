class Solution {
public:

    bool isPossible(vector<int>& bloom, int m, int k, int mid){
       int len = 0, boq = 0;
       for(int i = 0; i<bloom.size();i++){
            if(bloom[i]<=mid){
                len++;
                if(len==k){
                    boq++;
                    len = 0;
                }
            }
            else len = 0 ;
            if(boq==m)return true;
       }
       return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, h = 1e9;
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                h = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
    
        return ans;

    }
};