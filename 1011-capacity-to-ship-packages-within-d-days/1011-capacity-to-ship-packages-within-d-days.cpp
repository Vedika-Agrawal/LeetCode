class Solution {
public:
    
    int count(vector<int>v,int mid){
        int cnt= 1, curr_sum = 0;
        for(auto it: v){
           curr_sum+= it;
            if(curr_sum>mid)cnt++, curr_sum = it;
        }
        return cnt;
    }
    
   
    int shipWithinDays(vector<int>& v, int t) {
        int r = accumulate(v.begin(),v.end(),0);
        int l = max(r/t, *max_element(v.begin(),v.end()));
        
        while(l<r){
            int mid = (l+r)/2;
            if(count(v,mid)<=t) r= mid;
            else l = mid+1;
        }
        return l;
    }
  
};