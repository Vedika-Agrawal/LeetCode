class Solution {
public:
    double isPossible(vector<int>&v, int mid){
        int n = v.size();
        double time = 0.0;
        for(int i=0;i<v.size()-1; i++){
            int it = v[i];
            double t = (double)it/(double)mid;
            
            time+=ceil(t);
        }
        int it = v[n-1];
        time += (double)it/(double)mid;
        return time;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hr) {
        int  l =1, h  = 1e7;
        int ans = -1;
        while(l<=h){
            double mid = (l+h)/2;
            if(isPossible(dist, mid)<=hr){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};