class Solution {
public:
    
//     bool isPossible(vector<int>v, int mid, int tt){
//         long long cnt= 0;
//         for(auto it : v){
//             cnt += mid/it;
//         }
//         return cnt>=tt;
//     }
    
    bool isPossible(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (int t : time) {
            actualTrips += givenTime / t;
        }
        return actualTrips >= totalTrips;
    }
    
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1LL * *max_element(time.begin(), time.end()) * totalTrips;
        while(l<r){
         long long mid =(l+r)/2;
            isPossible(time, mid, totalTrips)== true ? r = mid : l = mid+1;
            
        }  
        return l ;
    }
};