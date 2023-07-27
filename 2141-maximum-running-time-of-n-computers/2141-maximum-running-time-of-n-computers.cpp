class Solution {
public:
    #define  ll long long 
    
  bool isPossible(vector<int>& batteries, long long time, int computers){
        long long totTime = time*computers;
        
        for(long long bTime : batteries)
            totTime -= min(time, bTime);
        
        return (totTime <= 0);//if entire charge for all computers is drained, then we used all batteries, so it's a possible solution
    }
    
    


    ll maxRunTime(int n, vector<int>& bat) {
        // sort(bat.rbegin(),bat.rend());
        
        ll h  = accumulate(bat.begin(),bat.end(), (ll)0);
        ll l = 0;
        while(l<=h){
            ll mid = l + (h-l)/2;
            cout<<l<<" "<<mid<<" "<<h<<endl;
            if(isPossible(bat, mid, n)){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return l-1;
    }
};